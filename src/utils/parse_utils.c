/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:20:54 by madumerg          #+#    #+#             */
/*   Updated: 2024/10/07 11:42:09 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

int	verif_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W' && \
		c != 'E' && c != ' ')
		return (1);
	return (0);
}
