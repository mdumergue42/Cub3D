/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/07 19:12:04 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**ft_parse_map(char *map)
{
	int		fd;
	char	**parse_map;
	char	*save;
	char	*join;

	fd = open(map, O_RDONLY);
	save = get_next_line(fd);
	join = ft_calloc(1, 1);
	if (!join)
		return (NULL);
	while (save != NULL)
	{
		join = ft_strjoin(join, save);
		free(save);
		save = get_next_line(fd);
	}
	parse_map = ft_split(join, '\n');
	free(join);
	close(fd);
	return (parse_map);
}

int	main(int ac, char **av)
{
	if (check_err_arg(ac, av) == 1)
		return (1);
	return (0);
}
