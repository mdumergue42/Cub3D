/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:20:54 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/11 22:15:23 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
