/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:37:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/29 14:57:10 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/settings.h"
#include "mlx.h"
#include <game/game.h>
#include <game/utils_math.h>

void	change_direction(float speed, bool clockwise, t_player *player)
{
	if (clockwise)
		player->direction += speed;
	else
		player->direction -= speed;
	fix_ang(&player->direction);
}

int	key_hook(int key, void *param)
{
	t_render	*render;

	render = (t_render *)param;
	if (key == ESCAPE_KEY)
		return (mlx_loop_end(render->mlx));
	if (key == W_KEY)
	{
		render->player->coord.x += PLAYER_SPEED * cos(render->player->direction);
		render->player->coord.y += PLAYER_SPEED * sin(render->player->direction);
	}
	else if (key == S_KEY)
	{
		render->player->coord.x -= PLAYER_SPEED * cos(render->player->direction);
		render->player->coord.y -= PLAYER_SPEED * sin(render->player->direction);
	}
	else if (key == D_KEY)
		change_direction(PLAYER_ROT_SPEED, false, render->player);
	else if (key == A_KEY)
		change_direction(PLAYER_ROT_SPEED, true, render->player);
	printf("player coord x = %f, y = %f\n", render->player->coord.x, render->player->coord.y);
	mlx_destroy_image(render->mlx, render->img);
	render->img = mlx_new_image(render->mlx, WINDOW_W, WINDOW_H);
	render_frame(render);
	mlx_put_image_to_window(render->mlx, render->win, render->img, 0, 0);
	return (0);
}
