/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:05:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/09/16 18:49:37 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdint.h>
#include "mlx.h"

void	*get_player_image(t_cub *cub, uint8_t key_pressed)
{
	void	*img;

	img = mlx_new_image(cub->mlx, WINDOW_X, WINDOW_Y);

	if (key_pressed == W_KEY)
		cub->p_coord.y--;
	else if (key_pressed == S_KEY)
		cub->p_coord.y++;
	else if (key_pressed == D_KEY)
		cub->p_coord.x++;
	else if (key_pressed == A_KEY)
		cub->p_coord.x--;
	mlx_set_image_pixel(cub->mlx, img, cub->p_coord.x, cub->p_coord.y, WHITE);
	return (img);
}
