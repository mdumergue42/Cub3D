/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:36:07 by madumerg          #+#    #+#             */
/*   Updated: 2024/11/11 15:13:02 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

int	check_nb_color(char *r, char *g, char *b)
{
	if (ft_strlen(r) > 3 || ft_strlen(g) > 3 || ft_strlen(b) > 3 || \
		ft_atoi(r) > 255 || ft_atoi(g) > 255 || ft_atoi(b) > 255)
	{
		free(r);
		free(g);
		free(b);
		err_mess(ERR_COLOR);
		return (-1);
	}
	return (0);
}

int	save_color(char *tab, t_pars *pars, int j, int i)
{
	char	*r;
	char	*g;
	char	*b;

	i++;
	while (tab[i] != ',')
		i++;
	r = ft_strndup_color(tab, 1, i);
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
	free(r);
	free(g);
	free(b);
	return (0);
}

int	count_precise_char(char *tab, char c)
{
	int	ct;
	int	i;

	i = 0;
	ct = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			ct++;
		i++;
	}
	if (ct != 2)
		return (err_mess(WRONG_F_RGB));
	return (0);
}

void	assign_color(t_pars *pars, char *sign)
{
	if (ft_strcmp(sign, "F") == 0)
		pars->f_color = pars->color;
	if (ft_strcmp(sign, "C") == 0)
		pars->c_color = pars->color;
}

int	check_format_rgb(char *sign, char **tab, t_pars *pars)
{
	static int	ct_f;
	static int	ct_c;
	char		*str;

	str = multi_join(tab, count_tab(tab));
	if (!str)
		return (err_mess(CRASH));
	if (ft_strcmp(sign, "F") == 0)
		ct_f++;
	if (ft_strcmp(sign, "C") == 0)
		ct_c++;
	if (check_char_color(str) == 1 || count_precise_char(str, ',') == 1 \
		|| save_color(str, pars, 0, 0) == -1)
	{
		free(str);
		return (1);
	}
	if (ct_f > 1 || ct_c > 1)
	{
		free(str);
		return (err_mess(DUP_ACR));
	}
	assign_color(pars, sign);
	free(str);
	return (0);
}
