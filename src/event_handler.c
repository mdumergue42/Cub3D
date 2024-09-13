/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:37:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/09/12 14:40:22 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "game.h"

int	key_hook(int key, t_cub *cub)
{
	(void)mlx;
	if (key == ESCAPE_KEY)
		mlx_loop_end(cub->mlx);
	if (key == W_KEY)
		printf("UP\n");
	if (key == S_KEY)
		printf("DOWN\n");
	if (key == D_KEY)
		printf("RIGHT\n");
	if (key == A_KEY)
		printf("LEFT\n");
	return (0);
}
