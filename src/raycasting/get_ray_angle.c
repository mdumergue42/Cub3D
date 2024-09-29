/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:26:29 by adjoly            #+#    #+#             */
/*   Updated: 2024/09/29 16:46:44 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	get_ray_angle(t_player *player)
{
	uint16_t	x;
	float		ray_angle;

	x = 0;
	while (x < WINDOW_X)
	{
		ray_angle = player->direction - (FOV / 2) + (x / WINDOW_X) * FOV;
		player->ray_angle[x / RAY_SIZE].x = cos(ray_angle);
		player->ray_angle[x / RAY_SIZE].y = sin(ray_angle);
		x += RAY_SIZE;
	}
}
