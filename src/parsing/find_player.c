/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:57:11 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/29 20:37:45 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	search_letter(char **map, int i, char l)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == l)
			{
				if (i == 0)
					return (x);
				else if (i == 1)
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	count_player(char **map, t_pars *pars, int ct)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || \
				map[y][x] == 'E' || map[y][x] == 'W')
			{
				pars->l_player = map[y][x];
				ct++;
			}
			x++;
		}
		y++;
	}
	if (ct != 1)
		return (1);
	return (0);
}
