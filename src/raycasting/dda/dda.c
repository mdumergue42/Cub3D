/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:55:09 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/23 15:04:45 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/dda.h"
#include "game/settings.h"
#include "sys/types.h"
#include <stdint.h>
#include <stdio.h>

uint16_t	*dda(t_player *player, char **map)
{
	t_dda	dda[WINDOW_X / RAY_SIZE];
	float	*wall_dist;
	uint16_t *line_size;

	setup_dda(&dda, player);
	player->map_coords.x = player->coords.x - player->coords.x % MAP_CHUNK_SIZE;
	player->map_coords.y = player->coords.y - player->coords.y % MAP_CHUNK_SIZE;
	while_dda(&dda, map, player);
	wall_dist = dist_dda(dda);
	line_size = line_dda(wall_dist);
	return (line_size);
}

/**
*	calculate size on screen
*	screen_height / per_wall_dist
*	(and get orientation)
*/
