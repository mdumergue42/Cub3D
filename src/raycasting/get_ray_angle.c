/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:26:29 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/06 17:58:04 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

void	get_ray_angle(t_player *player, t_dda (*dda)[800])
{
	uint16_t	x;
	float		ray_angle;

	x = 0;
	while (x < WINDOW_X)
	{
		ray_angle = player->direction - (FOV / 2) + (x / WINDOW_X) * FOV;
		dda[x / RAY_SIZE]->ray_dir.x = cos(ray_angle);
		dda[x / RAY_SIZE]->ray_dir.y = sin(ray_angle);
		x += RAY_SIZE;
	}
}
