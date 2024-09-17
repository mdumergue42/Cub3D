/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:38:40 by adjoly            #+#    #+#             */
/*   Updated: 2024/09/17 10:47:26 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "parsing.h"
# include <stdint.h>

typedef struct s_cub
{
	void	*mlx;
	void	*win;
	void	*sprites;
	void	*img;
	char	**map;
	t_coord	p_coord;
}	t_cub;

# define ESCAPE_KEY 41
# define W_KEY 26
# define S_KEY 22
# define A_KEY 4
# define D_KEY 7
# define WHITE 0xFFFFFFFF
# define WINDOW_Y 900
# define WINDOW_X 1600

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
 *
 */
void	*get_player_image(t_cub *cub, uint8_t key_pressed);

#endif
