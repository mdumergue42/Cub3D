/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:37:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/09/16 18:47:09 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "game.h"

int	key_hook(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	(void)cub;
	if (key == ESCAPE_KEY)
		mlx_loop_end(cub->mlx);
	if (key == W_KEY)
	{
		printf("UP\n");
		mlx_clear_window(cub->mlx, cub->win);
		mlx_put_image_to_window(cub->mlx, cub->win, get_player_image(cub, key), 0, 0);
	}
	if (key == S_KEY)
	{
		printf("DOWN\n");
		mlx_clear_window(cub->mlx, cub->win);
		mlx_put_image_to_window(cub->mlx, cub->win, get_player_image(cub, key), 0, 0);
	}
	if (key == D_KEY)
	{
		printf("RIGHT\n");
		mlx_clear_window(cub->mlx, cub->win);
		mlx_put_image_to_window(cub->mlx, cub->win, get_player_image(cub, key), 0, 0);
	}
	if (key == A_KEY)
	{
		printf("LEFT\n");
		mlx_clear_window(cub->mlx, cub->win);
		mlx_put_image_to_window(cub->mlx, cub->win, get_player_image(cub, key), 0, 0);
	}
	return (0);
}
