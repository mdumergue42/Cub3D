/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/12 11:22:31 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"
#include "mlx.h"

int	main(int ac, char **av)
{
	//char	**map;

	(void)ac;
	(void)av;
//	if (check_err_arg(ac, av) == 1)
//		return (1);
//	map = parse_map(av[1]);
//	if (verif_all_map(map) == 1)
//		return (1);
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 400, 400, "WTF");

	mlx_on_event(mlx, win, MLX_KEYDOWN, key_hook, mlx);

	mlx_loop(mlx);
	
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	return (0);
}
