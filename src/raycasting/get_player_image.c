/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:05:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/24 11:17:06 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "game/settings.h"
#include "math.h"
#include <stdio.h>

void	change_direction(double speed, bool clockwise, t_player *player)
{
	if (clockwise)
		player->direction -= speed;
	else
		player->direction += speed;
	if (player->direction >= 2 * M_PI)
		player->direction = 0;
	else if (player->direction < 0)
		player->direction = 2 * M_PI; 
}

void	get_player_image(t_cub *cub)
{
	print_map(cub);
	draw_square(cub, (t_coord){cub->player.coords.x - 2, cub->player.coords.y - 2}, \
			 5, WHITE);
}
