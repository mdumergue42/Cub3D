/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectwo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:32:14 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/02 15:51:49 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTWO_H
# define VECTWO_H

# include <stdint.h>

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

/* ------------------ Vec2 Utils ------------------ */

/**
 *	@brief	Gives you the distance between two point
 */
float	vec2_dist(t_vec2 first, t_vec2 second);

/**
 *	@brief	Just add second to first
 */
void	vec2_add(t_vec2 *first, t_vec2 second);

/**
 *	@brief	Just substract second to first
 */
void	vec2_sub(t_vec2 *first, t_vec2 second);

/**
 *	@brief	Multiply a vec2 by a number n and returns it
 */
t_vec2	vec2_mul_ret(t_vec2 vec, float n);
#endif
