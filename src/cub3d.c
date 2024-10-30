/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/10/30 10:02:56 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game/game.h"
#include "game/settings.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_render	render;
	t_map		world;
	t_player	player;

	render.player = &player;
	render.world = &world;
	world.celling = 0xffffa07a;
	world.floor = 0xffadd8e6;
	world.arr = ft_split("11111 10001 10001 10001 11111", ' ');
	world.size.x = 5;
	world.size.y = 5;
	player.coord.x = 1;
	player.coord.y = 1;
	player.direction = 0;
	render.mlx = mlx_init();
	render.win = mlx_new_window(render.mlx, WINDOW_W, WINDOW_H, "WTF");
	render.img = mlx_new_image(render.mlx, WINDOW_W, WINDOW_H);
	render_frame(&render);
	mlx_put_image_to_window(render.mlx, render.win, render.img, 0, 0);
	(void)ac;
	(void)av;
	mlx_on_event(render.mlx, render.win, MLX_KEYDOWN, key_hook, &render);
	mlx_loop(render.mlx);
	mlx_destroy_image(render.mlx, render.img);
	mlx_destroy_window(render.mlx, render.win);
	mlx_destroy_display(render.mlx);
	return (0);
}
