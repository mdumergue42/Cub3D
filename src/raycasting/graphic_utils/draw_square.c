/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:09:52 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/06 15:41:55 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "mlx.h"

void	draw_square(t_cub *cub, t_coord coord, uint16_t size, int color)
{
	t_coord	start;

	start = coord;
	while (coord.x - start.x <= size)
	{
		coord.y = start.y;
		while (coord.y - start.y <= size)
		{
			mlx_set_image_pixel(cub->mlx, cub->img, coord.x, coord.y, color);
			coord.y++;
		}
		coord.x++;
	}
}