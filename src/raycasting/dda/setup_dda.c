/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:47:14 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/24 12:40:00 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/settings.h"
#include "game/dda.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

void	get_side_dist(t_dda *dda, t_player *player)
{
	if (dda->ray_dir.x < 0)
	{
		dda->side_dist.x = (player->coords.x - player->map_coords.x) * dda->delta_dist.x;
		dda->step.x	= -MAP_CHUNK_SIZE;
	}
	else
	{
		dda->side_dist.x = ((player->map_coords.x + MAP_CHUNK_SIZE) - player->coords.x) * dda->delta_dist.x;
		dda->step.x = MAP_CHUNK_SIZE;
	}
	if (dda->ray_dir.y < 0)
	{
		dda->side_dist.y = (player->coords.y - player->map_coords.y) * dda->delta_dist.y;
		dda->step.y	= -MAP_CHUNK_SIZE;
	}
	else
	{
		dda->side_dist.y = (player->map_coords.y + MAP_CHUNK_SIZE - player->coords.y) * dda->delta_dist.y;
		dda->step.y = MAP_CHUNK_SIZE;
	}
}

void	setup_dda(t_dda (*dda)[WINDOW_X / RAY_SIZE], t_player *player)
{
	size_t	i;

	i = 0;
	get_ray_angle(player, dda);
	while (i < WINDOW_X / RAY_SIZE)
	{
		(*dda)[i].delta_dist.x = fabsf(MAP_CHUNK_SIZE / (*dda)[i].ray_dir.x);
		(*dda)[i].delta_dist.y = fabsf(MAP_CHUNK_SIZE / (*dda)[i].ray_dir.y);
		printf("%f \n", (*dda)[i].delta_dist.x);
		printf("%f \n", (*dda)[i].delta_dist.y);
		get_side_dist(&(*dda)[i], player);
		printf("side %f \n", (*dda)[i].side_dist.x);
		printf("side %f \n", (*dda)[i].side_dist.y);
		i++;
	}
}
