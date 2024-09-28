/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:36:07 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/28 17:08:01 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_nb_color(char *r, char *g, char *b)
{
	if (ft_strlen(r) > 3 || ft_strlen(g) > 3 || ft_strlen(b) > 3 || \
		ft_atoi(r) > 255 || ft_atoi(g) > 255 || ft_atoi(b) > 255)
		return (-1);
	return (0);
}

int	save_color(char *tab, t_pars *pars, int j)
{
	char	*r;
	char	*g;
	char	*b;
	int		i;

	i = 0;
	while (tab[i] != ',')
		i++;
	r = ft_strndup_color(tab, 0, i);
	i += 1;
	j = i;
	while (tab[i] != ',')
		i++;
	g = ft_strndup_color(tab, j, i);
	i += 1;
	j = i;
	while (tab[i])
		i++;
	b = ft_strndup_color(tab, j, i);
	if (check_nb_color(r, g, b) == -1)
		return (-1);
	pars->color = create_argb(ft_atoi(r), ft_atoi(g), ft_atoi(b));
	return (0);
}

int	count_precise_char(char *str, char c)
{
	int	ct;
	int	i;

	i = 0;
	ct = 0;
	while (str[i])
	{
		if (str[i] == c)
			ct++;
		i++;
	}
	if (ct != 2)
		return (1);
	return (0);
}

int	check_format_rgb(char *sign, char **tab, t_pars *pars)
{
	if (count_tab(tab) > 2)
		return (err_mess(NOT_FOUND));
	if (check_char_color(tab[1]) == 1)
		return (err_mess(INVALID_CHAR));
	if (count_precise_char(tab[1], ',') == 1)
		return (err_mess(WRONG_F_RGB));
	if (save_color(tab[1], pars, 0) == -1)
		return (err_mess(ERR_COLOR));
	if (ft_strcmp(sign, "F") == 0)
		pars->f_color = pars->color;
	else if (ft_strcmp(sign, "C") == 0)
		pars->c_color = pars->color;
	return (0);
}
