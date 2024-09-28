/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:40:12 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/28 17:32:55 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*fill_line(char *l, int size)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_calloc(sizeof(char), size + 1);
	if (!tmp)
		return (NULL);
	while (l[j])
	{
		tmp[i] = l[j];
		i++;
		j++;
	}
	if (i < size)
	{
		while (i <= size - 1)
		{
			tmp[i] = ' ';
			i++;
		}
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**alloc_map(char **old_map, int size)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = ft_calloc(sizeof(char *), ft_count_line_map(old_map, 0) + 1);
	if (!tmp)
		return (NULL);
	while (old_map[j])
	{
		tmp[i] = fill_line(old_map[j], size);
		if (tmp[i] == NULL)
			return (NULL);
		i++;
		j++;
	}
	tmp[i] = NULL;
	return (tmp);
}

int	line_char(char *l)
{
	int	i;

	i = 0;
	while (l[i])
	{
		if (actual_char(l[i]) == 0)
			return (1);
		else
			i++;
	}
	return (0);
}

int	last_first_line(char **map)
{
	int	y;
	int	tmp;

	tmp = ft_count_line_map(map, 0);
	y = 0;
	while (map[y])
	{
		if ((y == 0 && line_char(map[y]) == 1) || \
			(y == (tmp - 1) && line_char(map[y]) == 1))
			return (1);
		else
			y++;
	}
	return (0);
}
