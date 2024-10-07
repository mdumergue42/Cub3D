/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:46:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/07 17:08:57 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/dda.h"

void	while_dda(t_dda (*dda)[800], char **map, t_coord map_coord)
{
	dda->wall_hit = false;
	while (!dda->wall_hit)
	{
		if (dda->side_dist.x < dda->side_dist.y)
		{
			dda->side_dist.x += dda->delta_dist.x;
			map_coord.x += dda->step.x;
			dda->wall_side = HORIZONTAL;
		}
		else
		{
			dda->side_dist.y += dda->delta_dist.y;
			map_coord.y += dda->step.y;
			dda->wall_side = VERTICAL;
		}
		if (map[map_coord.x][map_coord.y] == '1')
			dda->wall_hit = true;
	}
}
