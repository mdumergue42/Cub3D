/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:04:10 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/23 15:00:05 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "typedef.h"
# include "settings.h"
# include <stdint.h>

/**
 *	@brief		Function used to get all the ray angle
 *
 *	@param player	The address of the t_player struct
 *	@param dda		The address of the t_dda struct
 */
void		get_ray_angle(t_player *player, t_dda (*dda)[800]);

/**
 *	@brief		Function used to setup all the dda variable prior to casting
 *				the rays
 *
 *	@param player	The address of the t_player struct
 *	@param dda		The address of the t_dda struct
 *
 */
void		setup_dda(t_dda (*dda)[800], t_player *player);

/**
 *	@brief		Function used to cast all the rays
 *
 *	@param dda			The address of the t_dda struct
 *	@param map			The map as a char **
 *	@param map_coord	The coordinate of the player on the map_grid
 */
void		while_dda(t_dda (*dda)[800], char **map, t_player *player);

	/// NEED TO COMBINE THOSE IF NOT USEFULL TO SEPARATE
/**
 *	@brief		Function used to get the distance from the player of all rays
 *
 *	@param dda			The address of the t_dda struct
 */
float		*dist_dda(t_dda dda[WINDOW_X / RAY_SIZE]);

/**
 *	@brief		Function used to get the size of the line to be printed on the screen
 *
 *	@param dda			The array of the all the distance to the wall of the rays
 */
uint16_t	*line_dda(float *wall_dist);

uint16_t	*dda(t_player *player, char **map);
#endif
