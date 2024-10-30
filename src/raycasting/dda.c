/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:55:09 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/30 14:42:06 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/vectwo.h"
#include <game/settings.h>
#include <game/dda.h>
#include <math.h>

void	setup_dda_hor(t_player *play, t_ray *ray, t_dda *dda)
{
	dda->h = true;
	dda->s = true;
	ray->tan = tan(ray->angle);
	if (cos(ray->angle) < -0.001)
	{
		ray->offset.x = -CHUNK_SIZE;
		ray->offset.y = CHUNK_SIZE * ray->tan;
		ray->pos.x = (((int)play->coord.x >> 6) << 6) - 0.001;
		ray->pos.y -= (play->coord.x - ray->pos.x) * ray->tan + play->coord.y;
	}
	else if(cos(ray->angle) > 0.001)
	{
		ray->offset.x = CHUNK_SIZE;
		ray->offset.y = -CHUNK_SIZE * ray->tan;
		ray->pos.x = (((int)play->coord.x >> 6) << 6) + CHUNK_SIZE;
		ray->pos.y -= (play->coord.x - ray->pos.x) * ray->tan + play->coord.y;
	}
	else
	{
		dda->s = false;
		ray->pos.x = play->coord.x;
		ray->pos.y = play->coord.y;
	}
}

void	setup_dda_ver(t_player *play, t_ray *ray, t_dda *dda)
{
	dda->s = true;
	dda->h = false;
	ray->tan = 1 / tan(ray->angle);
	if (sin(ray->angle) < -0.001)
	{
		ray->offset.y = CHUNK_SIZE;
		ray->offset.x = -CHUNK_SIZE * ray->tan;
		ray->pos.y = (((int)play->coord.y >> 6) << 6) - CHUNK_SIZE;
		ray->pos.x = (play->coord.y - ray->pos.y) * ray->tan + play->coord.x;
	}
	else if(sin(ray->angle) > 0.001)
	{
		ray->offset.y = -CHUNK_SIZE;
		ray->offset.x = CHUNK_SIZE * ray->tan;
		ray->pos.y = (((int)play->coord.y >> 6) << 6) + 0.001;
		ray->pos.x -= (play->coord.y - ray->pos.y) * ray->tan + play->coord.x;
	}
	else
	{
		dda->s = false;
		ray->pos.x = play->coord.x;
		ray->pos.y = play->coord.y;
	}
}

void	dda_loop(t_dda	*dda, t_ray	*ray, t_map *map, t_player *play)
{
	uint16_t	w;
	uint16_t	h;

	w = map->size.x;
	h = map->size.y;
	while (dda->s && dda->i)
	{
		dda->map.x = (int)(ray->pos.x / 64);
		dda->map.y = (int)(ray->pos.y / 64);
		printf("%f, %f\n", ray->pos.x, ray->pos.y);
		if (dda->map.x >= 0 && dda->map.x < w && dda->map.y >= 0 && dda->map.y < h && \
				map->arr[(int)dda->map.y][(int)dda->map.x] ==  '1')
		{
			dda->i = 0;
			if (dda->h)
				dda->distance.y = vec2_dist(play->coord, ray->pos);
			else
				dda->distance.x = vec2_dist(play->coord, ray->pos);
		}
		else
		{
			vec2_add(&ray->pos, ray->offset);
			dda->i--;
		}
	}
}

void	dda_algo(t_render *render, t_dda *dda, t_ray *ray)
{
	setup_dda_hor(render->player, ray, dda);
	dda->i = render->world->size.y;
	dda_loop(dda, ray, render->world, render->player);
	dda->hori.x = ray->pos.x;
	dda->hori.y = ray->pos.y;
	setup_dda_ver(render->player, ray, dda);
	dda->i = render->world->size.x;
	dda_loop(dda, ray, render->world, render->player);
	dda->vert.x = ray->pos.x;
	dda->vert.y = ray->pos.y;
	if (dda->distance.y < dda->distance.x)
	{
		ray->pos.x = fabsf(dda->hori.x);
		ray->pos.y = fabsf(dda->hori.y);
		ray->distance = dda->distance.x;
	}
	else
	{
		ray->pos.x = fabsf(dda->vert.x);
		ray->pos.y = fabsf(dda->vert.y);
		ray->distance = dda->distance.y;
	}
}
