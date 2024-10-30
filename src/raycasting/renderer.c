/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:48:39 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/29 14:22:37 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/utils_math.h"
#include "mlx.h"
#include <game/dda.h>
#include <game/settings.h>
#include <game/game.h>

void	draw_floor(t_render *render)
{
	size_t	x;
	size_t	y;

	y = WINDOW_H / 2;
	while(y < WINDOW_H - 1)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			mlx_set_image_pixel(render->mlx, render->img, x, y, render->world->floor);
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
	while(y < WINDOW_H / 2)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			mlx_set_image_pixel(render->mlx, render->img, x, y, render->world->celling);
			x++;
		}
		y++;
	}
}

void	print_line(t_render *render, t_ray *ray, int x)
{
	int	line;
	int	line_start;
	int	y;
	int	j;

	line = (CHUNK_SIZE * WINDOW_H) / ray->distance;
	line_start = -line / 2 + WINDOW_H / 2;
	y = 0;
	while (y < line)
	{
		j = -1;
		while (++j <= RAY_SIZE)
			mlx_set_image_pixel(render->mlx, render->img, x + j, line_start + y, WHITE);
		y++;
	}
}

void	render_frame(t_render *render)
{
	size_t	i;
	t_dda	dda;
	t_ray	ray;
	float	ang;

	i = WINDOW_W;
	ray.angle = render->player->direction - (M_PI / 180) / (FOV / 2);
	fix_ang(&ray.angle);
	draw_celling(render);
	draw_floor(render);
	while(i > 0)
	{
		dda_algo(render, &dda, &ray);
		ang = render->player->direction - ray.angle;
		fix_ang(&ang);
		ray.distance *= cos(ang);
		print_line(render, &ray, i);
		ray.angle += (M_PI / 180) / (WINDOW_W / FOV);
		fix_ang(&ray.angle);
		i -= RAY_SIZE;
	}
}
