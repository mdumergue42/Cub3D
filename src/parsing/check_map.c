/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:24:13 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/11 22:14:44 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_not_close(char after, char before, char down, char up)
{
	if (after == ' ' || after == '\0')
		return (1);
	else if (before == ' ' || before == '\0')
		return (1);
	else if (down == ' ' || down == '\0')
		return (1);
	else if (up == ' ' || up == '\0')
		return (1);
	return (0);
}

int	actual_char(char actual)
{
	if (actual == '0' || actual == 'N' || actual == 'W' || \
		actual == 'S' || actual == 'E')
		return (0);
	return (1);
}

int	check_map_close(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (actual_char(map[y][x]) == 0 && \
				(err_not_close(map[y][x + 1], map[y][x - 1], \
				map[y + 1][x], map[y - 1][x]) == 1))
				return (1);
			else
				x++;
		}
		y++;
	}
	return (0);
}

int	count_player(char **map)
{
	int	y;
	int	x;
	int	cpt;

	cpt = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || \
				map[y][x] == 'E' || map[y][x] == 'W')
				cpt++;
			x++;
		}
		y++;
	}
	if (cpt != 1)
		return (1);
	return (0);
}

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

int	check_char_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		convert_white_s(map[y]);
		while (map[y][x])
		{
			if (verif_char(map[y][x]) == 1)
				return (1);
			x++;
		}
		y++;
	}
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
