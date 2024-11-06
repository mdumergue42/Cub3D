/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:44:52 by madumerg          #+#    #+#             */
/*   Updated: 2024/11/06 12:52:08 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	all_data_verif(char **tab, t_pars *pars)
{
	if (detect_info(tab, pars) == 1)
	{
		free_tab(tab);
		return (1);
	}
	return (0);
}

int	check_info(char **file, t_pars *pars)
{
	char	**tab;
	int		i;
	int		ct;

	ct = 0;
	i = 0;
	while (file[i])
	{
		if (ct == 6)
			break ;
		if (space_line(file[i]) == 1)
		{
			ct++;
			tab = ft_split(file[i], ' ');
			if (tab == NULL || all_data_verif(tab, pars) == 1)
				return (1);
			free_tab(tab);
		}
		i++;
	}
	if (pars->f_color == 0 || pars->c_color == 0 || pars->ea_png == NULL || \
		pars->no_png == NULL || pars->so_png == NULL || pars->we_png == NULL)
		return (err_mess(NOT_FOUND));
	return (0);
}

int	verif_info_file(char *av, t_pars *pars)
{
	char	**map;

	map = parse_file(av, 0, 1);
	if (map == NULL)
		return (err_mess(CRASH));
	if (check_info(map, pars) == 1 || all_skip(map, pars) == 1)
	{
		free_tab(map);
		return (1);
	}
	free_tab(map);
	return (0);
}

int	verif_all_map(char **map, t_pars *pars)
{
	if (longest_line(map) == 1)
		return (1);
	pars->map = alloc_map(map, longest_line(map));
	if (pars->map == NULL)
		return (err_mess(CRASH));
	if (check_char_map(pars->map) == 1)
		return (err_mess(WRONG_CHAR));
	if (count_player(pars->map, pars, 0) == 1)
		return (err_mess(ERR_PLAYER));
	if (check_map_close(pars->map) == 1)
		return (err_mess(NOT_CLOSE));
	pars->coor.x = search_letter(pars->map, 0, pars->l_player);
	pars->coor.y = search_letter(pars->map, 1, pars->l_player);
	return (0);
}

char	**parse_file(char *map, int ct, int i)
{
	int		fd;
	char	**parse_map;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ct = count_line_file(fd);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	parse_map = ft_calloc(sizeof(char *), ct + 1);
	if (!parse_map)
	{
		close(fd);
		return (NULL);
	}
	parse_map[0] = get_next_line(fd);
	while (i <= ct)
	{
		parse_map[i] = get_next_line(fd);
		i++;
	}
	close (fd);
	return (parse_map);
}
