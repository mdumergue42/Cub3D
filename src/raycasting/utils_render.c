/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:46:57 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/10 16:49:17 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "game/dda.h"
#include "game/render.h"
#include <mlx.h>

void	draw_floor(t_render *render)
{
	size_t	x;
	size_t	y;

	y = WINDOW_H / 2;
	while (y < WINDOW_H)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			mlx_set_image_pixel(render->mlx, render->img, x, y, \
				render->world->floor);
			x++;
		}
		y++;
	}
}

void	draw_celling(t_render *render)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < WINDOW_H / 2)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			mlx_set_image_pixel(render->mlx, render->img, x, y, \
				render->world->celling);
			x++;
		}
		y++;
	}
}

void	*get_texture(bool hor, t_render *render, t_ray *ray)
{
	if (hor)
	{
		if (ray->angle < M_PI)
			return (&render->texture[0]);
		else
			return (&render->texture[2]);
	}
	else
	{
		if (ray->angle <= 3 * M_PI / 2 && ray->angle >= M_PI / 2)
			return (&render->texture[1]);
		else
			return (&render->texture[3]);
	}
}
