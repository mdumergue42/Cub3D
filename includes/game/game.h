/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:38:40 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/24 11:38:56 by adjoly           ###   ########.fr       */
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

# include "dda.h"
# include "settings.h"
# include "parsing.h"
# include "typedef.h"

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
 *	@brief		This function is used to create an image with the player position
 *
 *	@param cub	The address of a t_cub struct filled with mlx data and other 
 *				thing
 */
void	get_player_image(t_cub *cub);

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
void	change_direction(double speed, bool clockwise, t_player *player);

/**
 *	@brief		Function used to draw a square
 *
 *	@param cub		The adress of a t_cub struct
 *	@param coord	The coordinate of the printed square
 *	@param size		The size of the printed square
 *	@param color	The color of the printed square
 */
void	draw_square(t_cub *cub, t_coord coord, uint16_t size, int color);

/**
 *	@brief		Function used to draw the map
 *
 *	@param cub	The address of the t_cub struct
 */
void	print_map(t_cub *cub);

#endif
