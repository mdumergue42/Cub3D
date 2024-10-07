/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:12:28 by madumerg          #+#    #+#             */
/*   Updated: 2024/10/07 11:47:14 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_count_line_map(char **file, int y)
{
	while (file[y])
		y++;
	return (y);
}

int	replace_nl(char *l)
{
	int	i;

	i = 0;
	while (l[i])
	{
		if (l[0] == '\n')
			return (err_mess(WRONG_CHAR));
		if (l[i] == '\n')
			l[i] = '\0';
		i++;
	}
	return (0);
}

int	recup_map(char **old_map, int i, t_pars *pars)
{
	int	k;

	k = i;
	if (verif_all_map(&old_map[k], pars) == 1)
		return (1);
	return (0);
}

int	space_l_two(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
			i++;
		else
			break ;
	}
	if (line[i] != '\0')
		return (1);
	return (0);
}

int	all_skip(char **map, t_pars *pars)
{
	char	**tmp;
	int		ct;
	int		i;

	ct = 0;
	i = 0;
	tmp = map;
	while (tmp[i])
	{
		if (space_line(tmp[i]) == 1)
			ct++;
		if (ct == 6)
			break ;
		i++;
	}
	i += 1;
	while (tmp[i] && space_l_two(tmp[i]) != 1)
		i++;
	if (recup_map(map, i, pars) == 1)
		return (1);
	return (0);
}
