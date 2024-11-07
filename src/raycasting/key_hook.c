/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:37:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/07 12:20:02 by adjoly           ###   ########.fr       */
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
		render->player->coord.x += PLAYER_SPEED * \
			cos(render->player->direction);
		render->player->coord.y += PLAYER_SPEED * \
			-sin(render->player->direction);
	}
	else if (key == S_KEY)
	{
		render->player->coord.x -= PLAYER_SPEED * \
			cos(render->player->direction);
		render->player->coord.y -= PLAYER_SPEED * \
			-sin(render->player->direction);
	}
	else if (key == D_KEY)
		change_direction(PLAYER_ROT_SPEED, false, render->player);
	else if (key == A_KEY)
		change_direction(PLAYER_ROT_SPEED, true, render->player);
	return (0);
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
	return (0);
}
