/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/24 18:31:05 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"
#include "mlx.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	cub.map = (char *[]){
		"1111111\0",
		"1000101\0",
		"1000101\0",
		"1000001\0",
		"1111111\0",
		NULL
	};
	(void)ac;
	(void)av;
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, 600, 600, "WTF");
	cub.player.coords.x = 100;
	cub.player.coords.y = 100;
	cub.img = mlx_new_image(cub.mlx, 600, 600);
	get_player_image(&cub, 0);
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img, 0, 0);
	mlx_on_event(cub.mlx, cub.win, MLX_KEYDOWN, key_hook, &cub);
	mlx_loop(cub.mlx);
	mlx_destroy_window(cub.mlx, cub.win);
	mlx_destroy_display(cub.mlx);
	return (0);
}
