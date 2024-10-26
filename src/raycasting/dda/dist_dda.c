/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:26:19 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/23 14:10:52 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/dda.h"
#include <stddef.h>
#include "game/settings.h"
#include "libft.h"

float	*dist_dda(t_dda dda[WINDOW_X / RAY_SIZE])
{
	size_t	i;
	float	*wall_dist;

	i = 0;
	wall_dist = ft_calloc(WINDOW_X / RAY_SIZE + 1, sizeof(float));
	if (!wall_dist)
		return (NULL);
	while (i < WINDOW_X / RAY_SIZE)
	{
		if (dda[i].wall_side == HORIZONTAL)
			wall_dist[i] = dda[i].side_dist.x - dda[i].delta_dist.x;
		else
			wall_dist[i] = dda[i].side_dist.y - dda[i].delta_dist.y;
		i++;
	}
	return (wall_dist);
}
