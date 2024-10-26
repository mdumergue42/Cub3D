/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:27:44 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/22 13:03:40 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/settings.h"
#include "game/dda.h"
#include <stdlib.h>

uint16_t	*line_dda(float *wall_dist)
{
	uint16_t	i;
	uint16_t	*line_size;

	i = 0;
	line_size = malloc(WINDOW_X / RAY_SIZE * sizeof(uint16_t));
	while (i < WINDOW_X / RAY_SIZE)
	{
		line_size[i] = WINDOW_Y * MAP_CHUNK_SIZE / wall_dist[i];
		i++;
	}
	return (line_size);
}
