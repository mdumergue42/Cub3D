/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:37:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/04 15:29:00 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "parsing.h"
#include "game/game.h"

int	key_hook(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	(void)cub;
	if (key == ESCAPE_KEY)
	{
		mlx_loop_end(cub->mlx);
		mlx_destroy_image(cub->mlx, cub->img);
	}
	if (key == W_KEY || key == S_KEY || key == D_KEY || key == A_KEY)
	{
		mlx_clear_window(cub->mlx, cub->win);
		mlx_destroy_image(cub->mlx, cub->img);
		cub->img = mlx_new_image(cub->mlx, WINDOW_X, WINDOW_Y);
		get_player_image(cub, key);
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	}
	return (0);
}
