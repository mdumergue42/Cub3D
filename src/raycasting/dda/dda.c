/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:55:09 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/07 19:04:07 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/dda.h"
#include "game/settings.h"

void	dda(t_player *player, char **map)
{
	t_dda	dda[800];
	t_coord	map_coord;

	setup_dda(&dda, player);
	map_coord.x = player->coords.x - player->coords.x % MAP_CHUNK_SIZE;
	map_coord.y = player->coords.y - player->coords.y % MAP_CHUNK_SIZE;
	while_dda(&dda, map, map_coord);
	
}

/**
*	calculate distance from wall
*	perp_wall_dist = (map_y - player_y + (1 - step_y) / 2) / ray_dir_y
*
*	calculate size on screen
*	screen_height / per_wall_dist
*
*	print on screen
*
*/
