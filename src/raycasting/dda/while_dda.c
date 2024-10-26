/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:46:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/23 15:03:03 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/dda.h"
#include "game/settings.h"
#include <stdio.h>

void	while_dda(t_dda (*dda)[WINDOW_X / RAY_SIZE], char **map, t_player *player)
{
	uint16_t	i;
	t_coord		map_coord;

	i = 0;
	while (i < WINDOW_X / RAY_SIZE)
	{
		(*dda)[i].wall_hit = false;
		map_coord.x = player->map_coords.x;
		map_coord.y = player->map_coords.y;
		while (!(*dda)[i].wall_hit)
		{
			if ((*dda)[i].side_dist.x < (*dda)[i].side_dist.y)
			{
				(*dda)[i].side_dist.x += (*dda)[i].delta_dist.x;
				map_coord.x += (*dda)[i].step.x;
				(*dda)[i].wall_side = HORIZONTAL;
			}
			else
			{
				(*dda)[i].side_dist.y += (*dda)[i].delta_dist.y;
				map_coord.y += (*dda)[i].step.y;
				(*dda)[i].wall_side = VERTICAL;
			}
			if (map_coord.x < 0 || map_coord.y < 0 || map[map_coord.x / MAP_CHUNK_SIZE][map_coord.y / MAP_CHUNK_SIZE] == '1')
				(*dda)[i].wall_hit = true;
		}
		i++;
	}
}
