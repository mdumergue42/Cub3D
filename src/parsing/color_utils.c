/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:44:37 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/28 17:32:06 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_dup_color(t_pars *pars)
{
	if (pars->c_color < 0 || pars->f_color < 0)
		return (err_mess(NOT_FOUND));
	if (pars->c_color == pars->f_color)
		return (err_mess(DUP_COLOR));
	return (0);
}

int	create_argb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
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
