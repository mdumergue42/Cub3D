/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:44:37 by madumerg          #+#    #+#             */
/*   Updated: 2024/10/05 17:52:43 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	create_argb(int r, int g, int b)
{
	return (255 << 24 | r << 16 | g << 8 | b);
}

char	*ft_strndup_color(char *src, int start, int end)
{
	int		size;
	char	*dest;
	int		i;

	size = start;
	i = 0;
	dest = ft_calloc(sizeof(char), ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (size < end)
	{
		dest[i] = src[size];
		size++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	valid_char_color(char c)
{
	if (c == ',' || (c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	check_char_color(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (valid_char_color(tab[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
