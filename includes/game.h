/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:38:40 by adjoly            #+#    #+#             */
/*   Updated: 2024/09/29 16:47:32 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "parsing.h"
# include <stdint.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>

# define ESCAPE_KEY 41
# define W_KEY 26
# define S_KEY 22
# define A_KEY 4
# define D_KEY 7
# define WHITE 0xFFFFFFFF
# define WINDOW_Y 900
# define WINDOW_X 1600
# define PLAYER_ROT_SPEED (2 * M_PI) / 8
# define PLAYER_SPEED 3
# define MAP_CHUNK_SIZE 64
# define RAY_SIZE 2
# define FOV 60 * (M_PI / 180)

typedef struct s_ray_dir
{
	float	x;
	float	y;
}	t_ray_dir;

typedef struct s_player
{
	t_coord	coords;
	double	direction;
	t_ray_dir	ray_dir[WINDOW_X / RAY_SIZE];
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
void	get_player_image(t_cub *cub, uint8_t key_pressed);

/**
 *	@brief		This function is here to change the direction of the player
 *				by setting the t_player->direction and check overflow to be
 *				sure it stays between 0 and 2pi because it is expressed in
 *				radians
 *				
 *	@param speed		The speed a which the player rotate
 *	@param clockwise	The direction which the player rotate
 *	@param player		A pointer to a t_player struct
 *
 */
void	change_direction(double speed, bool clockwise, t_player *player);

/**
 *	@brief		Function used to draw a square
 *
 *	@param cub		The adress of a t_cub struct
 *	@param coord	The coordinate of the printed square
 *	@param size		The size of the printed square
 *	@param color	The color of the printed square
 *
 */
void	draw_square(t_cub *cub, t_coord coord, uint16_t size, int color);

/**
 *	@brief		Function used to draw the map
 *
 *	@param cub	The address of the t_cub struct
 */
void	print_map(t_cub *cub);
#endif
