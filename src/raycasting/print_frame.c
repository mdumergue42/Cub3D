/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:01:53 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/23 11:19:58 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/dda.h"
#include "mlx.h"
#include <stdlib.h>
#include "game/settings.h"

void	draw_rectangle(t_cub *cub, void *img, t_coord start, t_coord end)
{
	int	x;
	int	y;

	x = start.x;
	y = start.y;
	while (x < end.x)
	{
		while (y < end.y)
		{
			mlx_set_image_pixel(cub->mlx, img, x, y, WHITE);
			y++;
		}
		x++;
	}
}

void	*print_frame(t_cub *cub)
{
	uint16_t	*lines;
	int			start;
	int			stop;
	size_t		i;
	void		*img;

	lines = dda(&(cub->player), cub->map);
	img = mlx_new_image(cub->mlx, WINDOW_X, WINDOW_Y);
	i = 0;
	while (i < WINDOW_X / RAY_SIZE)
	{
		start = -lines[i] / 2 + WINDOW_Y / 2;
		if (start < 0)
			start = 0;
		stop = lines[i] / 2 + WINDOW_Y / 2;
		if (stop >= WINDOW_Y)
			stop = WINDOW_Y - 1;
		draw_rectangle(cub, img, (t_coord){i * RAY_SIZE, start}, (t_coord){i * RAY_SIZE + RAY_SIZE + 1, stop});
		i++;
	}
	return (img);
}
