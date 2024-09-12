/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:38:40 by adjoly            #+#    #+#             */
/*   Updated: 2024/09/12 11:40:07 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef	struct	s_cub 
{
	void	*mlx;
	void	*win;
	int		(*key_hook)(int, void*);
	void	*images;
	char	**map;
}	t_cub;

#define ESCAPE_KEY 41
#define W_KEY 26
#define S_KEY 22
#define A_KEY 4
#define D_KEY 7

/**
 *	@brief		This function is used to handle keypress
 *
 *	@param key	The key code of the pressed key
 *	@param mlx	The mlx pointer(internal to MacroLibX)
 *
 *	@return		Minilibx go brrrr(useless always 0)
 */
int	key_hook(int key, void *mlx);

#endif
