/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:38:40 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/02 15:55:39 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <unistd.h>
# include <stdint.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

# include "settings.h"

# include "vectwo.h"

# include "../parsing.h"

typedef struct s_map
{
	char	**arr;
	int		floor;
	int		celling;
	char	p_side;
	t_coord	p_spawnpoint;
	t_coord	size;
}	t_map;

typedef struct s_player
{
	t_vec2		coord;
	float		direction;
}	t_player;

typedef struct s_render
{
	t_map		*world;
	void		*mlx;
	void		*win;
	void		*img;
	t_player	*player;
	void		*texture[4];
}	t_render;

/**
 *	@brief		This function is used to handle keypress
 *
 *	@param key	The key code of the pressed key
 *	@param mlx	The mlx pointer(internal to MacroLibX)
 *
 *	@return		Minilibx go brrrr(useless always 0)
 */
int		key_hook(int key, void *param);

/**
 *	@brief		This function is here to change the direction of the player
 *				by setting the t_player->direction and check overflow to be
 *				sure it stays between 0 and 2pi because it is expressed in
 *				radians
 *				
 *	@param speed		The speed a which the player rotate
 *	@param clockwise	The direction which the player rotate
 *	@param player		A pointer to a t_player struct
 */
void	change_direction(float speed, bool clockwise, t_player *player);

/**
 *	@brief		Render a cub3d frame by executing a dda on every ray and 
 *				putting the pixel on the window
 *
 *	@param render	The render struct with everything i need
 */
void	render_frame(t_render *render);

#endif
