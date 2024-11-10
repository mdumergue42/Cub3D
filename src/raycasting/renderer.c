/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:48:39 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/10 16:49:53 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/utils_math.h"
#include "mlx.h"
#include <game/dda.h>
#include <game/settings.h>
#include <game/game.h>
#include <game/render.h>

int	get_color(t_ray *ray, t_dda *dda, t_render *render, \
				int y)
{
	int		x;	
	int		color;
	void	**texture;
	int		line_stop;
	int		line_size;

	line_size = (CHUNK_SIZE * WINDOW_H) / ray->distance;
	line_stop = line_size / 2 + WINDOW_H / 2;
	y = abs((line_stop - y) * TEXTURE_SIZE / line_size - 63);
	if (dda->distance.y < dda->distance.x)
	{
		x = (int)dda->hori.x % CHUNK_SIZE;
		texture = get_texture(true, render, ray);
	}
	else
	{
		x = (int)dda->vert.y % CHUNK_SIZE;
		texture = get_texture(false, render, ray);
	}
	color = mlx_get_image_pixel(render->mlx, *texture, x, y);
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
			mlx_set_image_pixel(render->mlx, render->img, x, line_start, \
						get_color(ray, dda, render, line_start));
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
