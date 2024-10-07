/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:04:10 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/06 18:48:38 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "typedef.h"

/**
 *	@brief		Function used to get all the ray angle
 *
 *	@param player	The address of the t_player struct
 *	@param dda		The address of the t_dda struct
 */
void	get_ray_angle(t_player *player, t_dda (*dda)[800]);

#endif
