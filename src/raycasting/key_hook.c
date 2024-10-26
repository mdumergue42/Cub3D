/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:37:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/24 11:41:30 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "game/game.h"

void	*print_frame(t_cub *cub);

int	key_hook(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	(void)cub;
	if (key == ESCAPE_KEY)
	{
		mlx_loop_end(cub->mlx);
		return (0);
	}
	if (key == W_KEY)
	{
		cub->player.coords.x += PLAYER_SPEED * cos(cub->player.direction);
		cub->player.coords.y += PLAYER_SPEED * sin(cub->player.direction);
	}
	else if (key == S_KEY)
	{
		cub->player.coords.x -= PLAYER_SPEED * cos(cub->player.direction);
		cub->player.coords.y -= PLAYER_SPEED * sin(cub->player.direction);
	}
	else if (key == D_KEY)
		change_direction(PLAYER_ROT_SPEED, false, &cub->player);
	else if (key == A_KEY)
		change_direction(PLAYER_ROT_SPEED, true, &cub->player);
	mlx_destroy_image(cub->mlx, cub->img);
	cub->img = print_frame(cub);
	//get_player_image(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}
