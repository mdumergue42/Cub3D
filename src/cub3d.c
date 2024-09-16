/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/16 18:39:38 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"
#include "mlx.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	(void)ac;
	(void)av;
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, 400, 400, "WTF");
	cub.p_coord.x = 100;
	cub.p_coord.y = 100;
	
	mlx_put_image_to_window(cub.mlx, cub.win, get_player_image(&cub, 0), 0, 0);

	mlx_on_event(cub.mlx, cub.win, MLX_KEYDOWN, key_hook, &cub);

	mlx_loop(cub.mlx);
	
	mlx_destroy_window(cub.mlx, cub.win);
	mlx_destroy_display(cub.mlx);
	return (0);
}
