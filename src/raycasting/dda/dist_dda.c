/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:26:19 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/08 21:40:08 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/dda.h"
#include <stdint.h>
#include <stddef.h>
#include "game/settings.h"

float	*dist_dda(t_dda dda[WINDOW_X / RAY_SIZE])
{
	size_t	i;
	float	wall_dist;

	wall_dist = ft_calloc(WINDOW_X / RAY_SIZE, sizeof(float));
	if (!wall_dist)
		return (NULL);
	while (dda[i])
	{
		if (dda[i].wall_side == HORIZONTAL)
			wall_dist[i] = dda[i].side_dist.x - dda[i].delta_dist.x;
		else
			wall_dist[i] = dda[i].side_dist.y - dda[i].delta_dist.y;
		i++;
	}
	return (wall_dist);
}
