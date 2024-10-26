/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/10/24 12:51:06 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game/game.h"
#include "game/settings.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

void	*print_frame(t_cub *cub);

int	main(int ac, char **av)
{
	t_cub	cub;

	cub.map = ft_calloc(6, sizeof(char *));
	cub.map[0] = ft_strdup("111111");
	cub.map[1] = ft_strdup("101001");
	cub.map[2] = ft_strdup("100001");
	cub.map[3] = ft_strdup("100001");
	cub.map[4] = ft_strdup("111111");
	cub.map[5] = NULL;
	(void)ac;
	(void)av;
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, WINDOW_X, WINDOW_Y, "WTF");
	cub.player.coords.x = 128;
	cub.player.coords.y = 128;
	cub.player.direction = 0;
	cub.img = print_frame(&cub);
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img, 0, 0);
	mlx_on_event(cub.mlx, cub.win, MLX_KEYDOWN, key_hook, &cub);
	mlx_loop(cub.mlx);
	mlx_destroy_image(cub.mlx, cub.img);
	mlx_destroy_window(cub.mlx, cub.win);
	mlx_destroy_display(cub.mlx);
	return (0);
}
