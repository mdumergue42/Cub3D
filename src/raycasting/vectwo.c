/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectwo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:47:29 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/01 16:07:33 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/vectwo.h"
#include <math.h>

float	vec2_dist(t_vec2 first, t_vec2 second)
{
	return (sqrt(powf(second.x - first.x, 2) + powf(second.y - first.y, 2)));
}

void	vec2_add(t_vec2 *first, t_vec2 second)
{
	first->x += second.x;
	first->y += second.y;
}

void	vec2_sub(t_vec2 *first, t_vec2 second)
{
	first->x -= second.x;
	first->y -= second.y;
}
