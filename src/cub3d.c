/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/10/14 12:32:14 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game/game.h"
#include "mlx.h"

void	*print_frame(t_cub *cub);

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
	cub.win = mlx_new_window(cub.mlx, WINDOW_X, WINDOW_Y, "WTF");
	cub.player.coords.x = 100;
	cub.player.coords.y = 100;
	cub.player.direction = 0;
	cub.img = print_frame(&cub);
	//get_player_image(&cub, 0);
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img, 0, 0);
	mlx_on_event(cub.mlx, cub.win, MLX_KEYDOWN, key_hook, &cub);
	mlx_loop(cub.mlx);
	mlx_destroy_window(cub.mlx, cub.win);
	mlx_destroy_display(cub.mlx);
	return (0);
}
