/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:01:03 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/09 15:49:41 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/settings.h"
#include "mlx.h"
#include "parsing.h"
#include "game/game.h"
#include "strings.h"

t_player	init_player(t_pars parsing)
{
	t_player	player;

	player.coord.x = parsing.coor.x * CHUNK_SIZE + (CHUNK_SIZE / 2);
	player.coord.y = parsing.coor.y * CHUNK_SIZE + (CHUNK_SIZE / 2);
	ft_bzero(player.key, 4);
	if (parsing.l_player == 'N')
		player.direction = M_PI / 2;
	else if (parsing.l_player == 'S')
		player.direction = -(M_PI / 2);
	else if (parsing.l_player == 'W')
		player.direction = M_PI;
	else if (parsing.l_player == 'E')
		player.direction = 0;
	return (player);
}

t_map	init_world(t_pars parsing)
{
	t_map	map;

	map.arr = parsing.map;
	map.size.x = ft_strlen(parsing.map[0]);
	map.size.y = ft_count_line_map(parsing.map, 0);
	map.floor = parsing.f_color;
	map.celling = parsing.c_color;
	return (map);
}

void	init_texture(t_render *render, t_pars parsing)
{
	int	i;

	render->texture[0] = mlx_png_file_to_image(render->mlx, parsing.no_png, &i, &i);
	render->texture[1] = mlx_png_file_to_image(render->mlx, parsing.we_png, &i, &i);
	render->texture[2] = mlx_png_file_to_image(render->mlx, parsing.so_png, &i, &i);
	render->texture[3] = mlx_png_file_to_image(render->mlx, parsing.ea_png, &i, &i);
}
