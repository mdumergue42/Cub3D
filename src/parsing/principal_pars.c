/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:44:52 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/16 14:58:26 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_data_verif(char **tab, t_pars *pars)
{
	if (detect_info(tab, pars) == 1)
		return (1);
	return (0);
}

int	check_info(char **l, t_pars *pars)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_calloc(sizeof(char *), 6);
	if (!tab)
		return (1);
	while (l[i])
	{
		tab = ft_split(l[i], ' ');
		if (all_data_verif(tab, pars) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	verif_info_file(char *av, t_pars *pars)
{
	char	**map;
	char	**f_part;

	(void)pars;
	map = parse_map(av);
	f_part = info_map(map);
	if (check_info(f_part, pars) == 1)
		return (1);
//	if (check_dup_img(pars) == 1)
//		return (1);
//	if (verif_all_map(map) == 1)
//		return (1);
	return (0);
}

int	verif_all_map(char **map)
{
	if (check_char_map(map) == 1)
		return (err_mess(WRONG_CHAR));
	if (count_player(map) == 1)
		return (err_mess(ERR_PLAYER));
	if (check_map_close(map) == 1)
		return (err_mess(NOT_CLOSE));
	return (0);
}

char	**parse_map(char *map)
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
