/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:09:17 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/06 17:58:25 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "mlx.h"
#include <stdio.h>

void	print_map(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
			{
				draw_square(cub, (t_coord){j * MAP_CHUNK_SIZE, i * MAP_CHUNK_SIZE}, MAP_CHUNK_SIZE, WHITE);
			}
			j++;
		}
		i++;
	}
}
