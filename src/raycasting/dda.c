/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:55:09 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/28 14:40:14 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/vectwo.h"
#include <game/settings.h>
#include <game/dda.h>
#include <math.h>

void	setup_dda_hor(t_player *play, t_ray *ray, t_dda *dda)
{
	dda->h = true;
	ray->tan = tan(ray->angle);
	if (cos(ray->angle) < -0.001)
	{
		ray->pos.x = (((int)play->coord.x >> 6) << 6) - 0.001;
		ray->pos.y -= (play->coord.x - ray->pos.x) * ray->tan + play->coord.y;
		ray->offset.x = -CHUNK_SIZE;
		ray->offset.y = -ray->offset.x * ray->tan;
	}
	else if(cos(ray->angle) > 0.001)
	{
		ray->pos.x = (((int)play->coord.x >> 6) << 6) + CHUNK_SIZE;
		ray->pos.y -= (play->coord.x - ray->pos.x) * ray->tan + play->coord.y;
		ray->offset.x = CHUNK_SIZE;
		ray->offset.y = -ray->offset.x * ray->tan;
	}
}

void	setup_dda_ver(t_player *play, t_ray *ray, t_dda *dda)
{
	dda->h = false;
	ray->tan = 1 / tan(ray->angle);
	if (sin(ray->angle) < -0.001)
	{
		ray->pos.y = (((int)play->coord.y >> 6) << 6) - 0.001;
		ray->pos.x = (play->coord.y - ray->pos.y) * ray->tan + play->coord.x;
		ray->offset.y = -CHUNK_SIZE;
		ray->offset.x = -ray->offset.y * ray->tan;
	}
	else if(sin(ray->angle) > 0.001)
	{
		ray->pos.y = (((int)play->coord.y >> 6) << 6) + CHUNK_SIZE;
		ray->pos.x -= (play->coord.y - ray->pos.y) * ray->tan + play->coord.x;
		ray->offset.y = CHUNK_SIZE;
		ray->offset.x = -ray->offset.y * ray->tan;
	}
}

void	dda_loop(t_dda	*dda, t_ray	*ray, t_map *map, t_player *play)
{
	uint16_t	w;
	uint16_t	h;

	w = map->size.x;
	h = map->size.y;
	while (dda->i)
	{
		dda->map.x = ((int)ray->pos.x >> 6);
		dda->map.y = ((int)ray->pos.x >> 6);
		if (dda->map.x >= 0 && dda->map.x < w && dda->map.y >= 0 && dda->map.y < h && \
				map->arr[(int)dda->map.y][(int)dda->map.x] ==  '1')
		{
			dda->i = 0;
			if (dda->h)
				dda->distance.x = vec2_dist(play->coord, ray->pos);
		}
		else
		{
			vec2_add(&ray->pos, ray->offset);
			dda->i--;
		}
	}
}

void	dda(t_player *player, t_render *render)
{
	t_dda		dda;
	t_ray		ray;

	setup_dda_hor(player, &ray, &dda);
	dda_loop(&dda, &ray, render->world, player);
	setup_dda_ver(player, &ray, &dda);
	dda_loop(&dda, &ray, render->world, player);
	if (dda.distance.x < dda.distance.y)
	{
		ray.pos.x = fabsf(dda.hori.x);
		ray.pos.y = fabsf(dda.hori.y);
		ray.distance = dda.distance.x;
	}
	else
	{
		ray.pos.x = fabsf(dda.vert.x);
		ray.pos.y = fabsf(dda.vert.y);
		ray.distance = dda.distance.y;
	}
}
