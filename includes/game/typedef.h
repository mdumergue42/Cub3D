/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:28:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/06 19:03:26 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "parsing.h"
# include <stdbool.h>

typedef struct s_coord_f
{
	float	x;
	float	y;
}	t_coord_f;

typedef struct s_step
{
	char	x;
	char	y;
}	t_step;

typedef struct s_player
{
	t_coord	coords;
	double	direction;
}	t_player;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	void		*sprites;
	void		*img;
	char		**map;
	t_player	player;
}	t_cub;

typedef enum s_wall_side
{
	HORIZONTAL,
	VERTICAL
}	t_wall_side;

typedef struct s_dda
{
	t_coord_f	ray_dir;
	t_coord_f	side_dist;
	t_coord_f	delta_dist;
	t_step		step;
	t_wall_side	wall_side;
	bool		wall_hit;

}	t_dda;

#endif
