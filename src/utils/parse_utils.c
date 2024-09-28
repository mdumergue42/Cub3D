/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:20:54 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/28 17:32:42 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	space_line(char *line)
{
	int	i;

	i = 0;
	convert_white_s(line);
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

char	**info_map(char **file)
{
	char	**f_part;
	int		i;
	int		j;

	i = 0;
	j = 0;
	f_part = ft_calloc(6 + 1, sizeof(char *));
	if (!f_part)
		return (NULL);
	while (i >= j)
	{
		if (j == 6)
			break ;
		if (space_line(file[i]) == 1)
		{
			f_part[j] = file[i];
			j++;
		}
		i++;
	}
	return (f_part);
}

int	verif_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W' && \
		c != 'E' && c != ' ')
		return (1);
	return (0);
}
