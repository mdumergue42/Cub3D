/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:04:36 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/28 14:37:10 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DDA_H
# define DDA_H

# include <math.h>

# include "game.h"
#include "game/vectwo.h"

typedef struct s_dda
{
	bool	h;
	int		i;
	t_vec2	map;
	t_vec2	vert;
	t_vec2	hori;
	t_vec2	distance;
}	t_dda;

typedef struct s_ray
{
	t_vec2	pos;
	float	tan;
	float	angle;
	t_vec2	offset;
	float	distance;
}	t_ray;

void	dda_algo(t_player *play, t_render *render);

#endif
