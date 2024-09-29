/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:05:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/09/29 14:44:28 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include "stdio.h"

void	change_direction(double speed, bool clockwise, t_player *player)
{
	if (clockwise)
		player->direction -= speed;
	else
		player->direction += speed;
	if (player->direction >= 2 * M_PI)
		player->direction -= 2 * M_PI;
	else if (player->direction < 0)
		player->direction += 2 * M_PI;
	printf("%f\n", player->direction);
}

void	get_player_image(t_cub *cub, uint8_t key_pressed)
{
	if (key_pressed == W_KEY)
	{
		cub->player.coords.x += PLAYER_SPEED * cos(cub->player.direction);
		cub->player.coords.y += PLAYER_SPEED * sin(cub->player.direction);
	}
	else if (key_pressed == S_KEY)
	{
		cub->player.coords.x -= PLAYER_SPEED * cos(cub->player.direction);
		cub->player.coords.y -= PLAYER_SPEED * sin(cub->player.direction);
	}
	else if (key_pressed == D_KEY)
		change_direction(PLAYER_ROT_SPEED, false, &cub->player);
	else if (key_pressed == A_KEY)
		change_direction(PLAYER_ROT_SPEED, true, &cub->player);
	print_map(cub);
	draw_square(cub, (t_coord){cub->player.coords.x - 2, cub->player.coords.y - 2}, \
			 5, WHITE);
}
