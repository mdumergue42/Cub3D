/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:48:39 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/10 15:44:00 by adjoly           ###   ########.fr       */
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

int	get_color(t_ray *ray, t_dda *dda, t_render *render, int line_start, int line_stop, int line_size)
{
	int	x;	
	int	h;
	int	color;
	void	**texture;

	(void)ray;
	line_stop = line_size / 2 + WINDOW_H / 2;
	if (dda->distance.y < dda->distance.x)
	{
		x = (int)dda->hori.x % CHUNK_SIZE;
		h = abs((line_stop - line_start) * TEXTURE_SIZE / line_size - 63);
		if (ray->angle < M_PI)
			texture = &render->texture[0];
		else
			texture = &render->texture[2];
		color = mlx_get_image_pixel(render->mlx, *texture, x, h);
	}
	else
	{
		x = (int)dda->vert.y % CHUNK_SIZE;
		h = abs((line_stop - line_start) * TEXTURE_SIZE / line_size - 63);
		if (ray->angle <= 3 * M_PI / 2 && ray->angle >= M_PI / 2)
			texture = &render->texture[1];
		else
			texture = &render->texture[3];
		color = mlx_get_image_pixel(render->mlx, *texture, x, h);
	}
	return (color);	
}

void	print_line(t_render *render, t_ray *ray, int x, t_dda *dda)
{
	int	line_size;
	int	line_stop;
	int	line_start;

	line_size = (CHUNK_SIZE * WINDOW_H) / ray->distance;
	line_start = -line_size / 2 + WINDOW_H / 2;
	line_stop = line_size / 2 + WINDOW_H / 2;
	if (line_start < 0)
		line_start = 0;
	if (line_stop > WINDOW_H)
		line_stop = WINDOW_H;
	while (line_start < line_stop)
	{
		if (x < WINDOW_W && x >= 0)
			mlx_set_image_pixel(render->mlx, render->img, x, line_start, get_color(ray, dda, render, line_start, line_stop, line_size));
		line_start++;
	}
}

void	render_frame(t_render *render)
{
	int		i;
	t_dda	dda;
	t_ray	ray;
	float	ang;

	i = WINDOW_W;
	ray.angle = render->player->direction - ((M_PI / 180) * ((float)FOV / 2));
	fix_ang(&ray.angle);
	draw_celling(render);
	draw_floor(render);
	while (i > -1)
	{
		dda_algo(render, &dda, &ray);
		ang = cos(render->player->direction - ray.angle);
		ray.distance *= ang;
		print_line(render, &ray, i, &dda);
		ray.angle += (M_PI / 180) / ((float)WINDOW_W / FOV);
		fix_ang(&ray.angle);
		i--;
	}
}
