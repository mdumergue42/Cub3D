/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:48:35 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/11 13:48:44 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

void	move_for_back(t_render *render, bool forward)
{
	if (forward)
	{
		render->player->coord.x += PLAYER_SPEED * \
			cos(render->player->direction);
		render->player->coord.y += PLAYER_SPEED * \
			-sin(render->player->direction);
	}
	else
	{
		render->player->coord.x -= PLAYER_SPEED * \
			cos(render->player->direction);
		render->player->coord.y -= PLAYER_SPEED * \
			-sin(render->player->direction);
	}
}

void	move_right_left(t_render *render, bool right)
{
	if (right)
	{
		render->player->coord.x += PLAYER_SPEED * \
			sin(render->player->direction);
		render->player->coord.y += PLAYER_SPEED * \
			cos(render->player->direction);
	}
	else
	{
		render->player->coord.x -= PLAYER_SPEED * \
			sin(render->player->direction);
		render->player->coord.y -= PLAYER_SPEED * \
			cos(render->player->direction);
	}
}
