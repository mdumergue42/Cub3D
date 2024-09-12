/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:20:54 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/12 16:20:31 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**info_map(char **file)
{
	char	**f_part;
	int	i;
	int	j;

	i = 0;
	j = 0;
	f_part = ft_calloc(6, sizeof(char *));
	if (!f_part)
		return (NULL);
	while (i < 6)
	{
		f_part[j] = file[i];
		j++;
		i++;
	}
	return (f_part);
}

void	convert_white_s(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 9 && str[i] <= 13)
			str[i] = 32;
		i++;
	}
}

int	verif_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W' && \
		c != 'E' && c != ' ')
		return (1);
	return (0);
}
