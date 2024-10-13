/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:55:09 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/13 17:27:17 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/dda.h"
#include "game/settings.h"

void	dda(t_player *player, char **map)
{
	t_dda	dda[WINDOW_X / RAY_SIZE];
	t_coord	map_coord;
	float	*wall_dist;
	float	*line_size;

	setup_dda(&dda, player);
	map_coord.x = player->coords.x - player->coords.x % MAP_CHUNK_SIZE;
	map_coord.y = player->coords.y - player->coords.y % MAP_CHUNK_SIZE;
	while_dda(&dda, map, map_coord);
	wall_dist = dist_dda(dda);
	
}

/**
*	calculate size on screen
*	screen_height / per_wall_dist
*	(and get orientation)
*/
