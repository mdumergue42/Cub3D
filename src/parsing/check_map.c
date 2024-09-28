/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:24:13 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/28 15:48:38 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_not_close(char after, char before, char down, char up)
{
	if (after == ' ' || after == '\0' || after == '\n')
		return (1);
	else if (before == ' ' || before == '\0' || before == '\n')
		return (1);
	else if (down == ' ' || down == '\0' || down == '\n')
		return (1);
	else if (up == ' ' || up == '\0' || up == '\n')
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
	if (last_first_line(map) == 1)
		return (1);
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

int	check_char_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
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
