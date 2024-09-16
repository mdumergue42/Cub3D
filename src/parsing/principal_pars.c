/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:44:52 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/13 10:43:50 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//int	check_info(char **l)
//{
//	
//}

//int	verif_info_map(char *av)
//{
//	char	**map;
//	char	**f_part;
//
//	map = parse_map(av);
//	f_part = info_map(map);
//	if (check_info(f_part) == 1)
//		return (1);
//	if (verif_all_map(map) == 1)
//		return (1);
//}

int	verif_all_map(char **map)
{
	if (check_char_map(map) == 1)
		return (err_mess(WRONG_CHAR));
	if (count_player(map) == 1)
		return (err_mess(ERR_PLAYER));
	if (check_map_close(map) == 1)
		return (err_mess(NOT_CLOSE));
	return (0);
}

char	**parse_map(char *map)
{
	int		fd;
	char	**parse_map;
	char	*save;
	char	*join;

	fd = open(map, O_RDONLY);
	save = get_next_line(fd);
	join = ft_calloc(1, 1);
	if (!join)
		return (NULL);
	while (save != NULL)
	{
		join = ft_strjoin(join, save);
		free(save);
		save = get_next_line(fd);
	}
	parse_map = ft_split(join, '\n');
	free(join);
	close(fd);
	return (parse_map);
}
