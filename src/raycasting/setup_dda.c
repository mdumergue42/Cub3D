/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:47:14 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/06 19:02:43 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include <stdbool.h>
#include <math.h>

void	get_side_dist(t_dda *dda, t_coord incell_coords, t_player *player)
{
	if (dda->ray_dir.x < 0)
	{
		dda->side_dist.x = incell_coords.x * dda->delta_dist.x;
		dda->step.x	= -MAP_CHUNK_SIZE;
	}
	else
	{
		dda->side_dist.x = (((int)player->coords.x + MAP_CHUNK_SIZE) - player->coords.x) * dda->delta_dist.x;
		dda->step.x = MAP_CHUNK_SIZE;
	}
	if (dda->ray_dir.y < 0)
	{
		dda->side_dist.y = incell_coords.y * dda->delta_dist.y;
		dda->step.y	= -MAP_CHUNK_SIZE;
	}
	else
	{
		dda->side_dist.y = (((int)player->coords.y + MAP_CHUNK_SIZE) - player->coords.y) * dda->delta_dist.y;
		dda->step.y = MAP_CHUNK_SIZE;
	}
}

void	setup_dda(t_player *player)
{
	t_dda	dda[WINDOW_X / RAY_SIZE];
	size_t	i;
	t_coord	incell_coords;

	i = 0;
	get_ray_angle(player, &dda);
	incell_coords.x = player->coords.x % MAP_CHUNK_SIZE;
	incell_coords.y = player->coords.y % MAP_CHUNK_SIZE;
	while (i < WINDOW_X / RAY_SIZE)
	{
		dda[i].delta_dist.x = abs((int)(MAP_CHUNK_SIZE / dda[i].ray_dir.x));
		dda[i].delta_dist.y = abs((int)(MAP_CHUNK_SIZE / dda[i].ray_dir.y));
		get_side_dist(&dda[i], incell_coords, player);
		i++;
	}
}
