/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/11/11 13:37:32 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game/game.h"
#include "game/settings.h"
#include "game/vectwo.h"
#include "libft.h"
#include "mlx.h"
#include "parsing.h"
#include <stdlib.h>
#include "utils.h"

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


int	loop(void *param)
{
	t_render	*render;

	render = (t_render *)param;
	mlx_destroy_image(render->mlx, render->img);
	if (render->player->key[0])
		move_for_back(render, true);
	if (render->player->key[2])
		move_for_back(render, false);
	if (render->player->key[3])
		move_right_left(render, true);
	if (render->player->key[1])
		move_right_left(render, false);
	if (render->player->key[4])
		change_direction(PLAYER_ROT_SPEED, false, render->player);
	if (render->player->key[5])
		change_direction(PLAYER_ROT_SPEED, true, render->player);
	render->img = mlx_new_image(render->mlx, WINDOW_W, WINDOW_H);
	render_frame(render);
	mlx_put_image_to_window(render->mlx, render->win, render->img, 0, 0);
	return (0);
}

void	delete_everything(t_pars *parsing, t_render *render)
{
	mlx_destroy_image(render->mlx, render->img);
	mlx_destroy_image(render->mlx, render->texture[0]);
	mlx_destroy_image(render->mlx, render->texture[1]);
	mlx_destroy_image(render->mlx, render->texture[2]);
	mlx_destroy_image(render->mlx, render->texture[3]);
	mlx_destroy_window(render->mlx, render->win);
	mlx_destroy_display(render->mlx);
	free_pars(parsing);
}

void	event_hook(t_render *render)
{
	mlx_on_event(render->mlx, render->win, MLX_KEYDOWN, key_down, render);
	mlx_on_event(render->mlx, render->win, MLX_KEYUP, key_up, render);
	mlx_on_event(render->mlx, render->win, MLX_WINDOW_EVENT, window_event, render);
}

int	main(int ac, char **av)
{
	t_render	render;
	t_map		world;
	t_player	player;
	t_pars		parsing;

	parsing = init_pars();
	if (basics_check(ac, av, &parsing))
	{
		free_pars(&parsing);
		return (EXIT_FAILURE);
	}
	render.mlx = mlx_init();
	render.win = mlx_new_window(render.mlx, WINDOW_W, WINDOW_H, "WTF");
	player = init_player(parsing);
	world = init_world(parsing);
	render.player = &player;
	render.world = &world;
	init_texture(&render, parsing);
	event_hook(&render);
	render.img = mlx_new_image(render.mlx, WINDOW_W, WINDOW_H);
	mlx_loop_hook(render.mlx, loop, &render);
	mlx_loop(render.mlx);
	delete_everything(&parsing, &render);
	return (EXIT_SUCCESS);
}
