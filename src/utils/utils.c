/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:57:13 by madumerg          #+#    #+#             */
/*   Updated: 2024/11/11 15:09:41 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_tab(char **tab)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (tab[i])
	{
		i++;
		ct++;
	}
	return (ct);
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

int	longest_line(char **line)
{
	int	i;
	int	stock;
	int	actual;

	stock = ft_strlen(line[0]);
	if (stock == 0)
		return (err_mess(MISS_MAP));
	i = 1;
	actual = 0;
	while (line[i])
	{
		actual = ft_strlen(line[i]);
		if (actual > stock)
			stock = actual;
		i++;
	}
	return (stock);
}

int	count_line_file(int fd)
{
	int		i;
	char	*gnl;

	i = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
		i++;
	}
	close (fd);
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
