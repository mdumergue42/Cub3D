/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:37:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/11 13:29:30 by adjoly           ###   ########.fr       */
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

int	key_down(int key, void *param)
{
	t_render	*render;

	render = (t_render *)param;
	if (key == ESCAPE_KEY)
		return (mlx_loop_end(render->mlx));
	if (key == W_KEY)
		render->player->key[0] = true;
	else if (key == A_KEY)
		render->player->key[1] = true;
	else if (key == S_KEY)
		render->player->key[2] = true;
	else if (key == D_KEY)
		render->player->key[3] = true;
	else if (key == RIGHT_KEY)
		render->player->key[4] = true;
	else if (key == LEFT_KEY)
		render->player->key[5] = true;
	return (0);
}

int	key_up(int key, void *param)
{
	t_render	*render;

	render = (t_render *)param;
	if (key == W_KEY)
		render->player->key[0] = false;
	else if (key == A_KEY)
		render->player->key[1] = false;
	else if (key == S_KEY)
		render->player->key[2] = false;
	else if (key == D_KEY)
		render->player->key[3] = false;
	else if (key == RIGHT_KEY)
		render->player->key[4] = false;
	else if (key == LEFT_KEY)
		render->player->key[5] = false;
	return (0);
}

int	window_event(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(((t_render *)param)->mlx);
	return (0);
}
