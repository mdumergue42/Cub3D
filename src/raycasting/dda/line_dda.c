/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:27:44 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/13 17:36:05 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/settings.h"

uint16_t	*line_dda(t_dda (*dda)[WINDOW_X / RAY_SIZE], float *wall_dist)
{
	uint16_t	i;
	uint16_t	*line_size;

	(void)dda;
	i = 0;
	line_size = malloc(WINDOW_X / RAY_SIZE * sizeof(uint16_t));
	while (wall_dist[i])
	{
		line_size[i] = (WINDOW_Y / wall_dist[i]);
		i++;
	}
	return (line_size);
}
