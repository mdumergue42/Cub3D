/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:38:32 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/16 14:38:35 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_dup_img(t_pars *pars)
{
	if (!pars->no_png || !pars->so_png || !pars->we_png || !pars->ea_png)
		return (err_mess(NOT_FOUND));
	if (ft_strcmp(pars->no_png, pars->so_png) == 0 || \
		ft_strcmp(pars->no_png, pars->we_png) == 0 || \
		ft_strcmp(pars->no_png, pars->ea_png) == 0 || \
		ft_strcmp(pars->so_png, pars->we_png) == 0 || \
		ft_strcmp(pars->we_png, pars->ea_png) == 0)
		return (err_mess(DUP_IMG));
	return (0);
}

int	assign_img_two(char *sign, char *path, t_pars *pars)
{
	if (ft_strcmp("WE", sign) == 0)
	{
		if (pars->we_png == NULL)
			pars->we_png = path;
		else
			return (err_mess(DUP_ACR));
	}
	else if (ft_strcmp("EA", sign) == 0)
	{
		if (pars->ea_png == NULL)
			pars->ea_png = path;
		else
			return (err_mess(DUP_ACR));
	}
	return (0);
}

int	assign_img(char *sign, char *path, t_pars *pars)
{
	if (ft_strcmp("NO", sign) == 0)
	{
		if (pars->no_png == NULL)
			pars->no_png = path;
		else
			return (err_mess(DUP_ACR));
	}
	else if (ft_strcmp("SO", sign) == 0)
	{
		if (pars->so_png == NULL)
			pars->so_png = path;
		else
			return (err_mess(DUP_ACR));
	}
	if (assign_img_two(sign, path, pars) == 1)
		return (1);
	return (0);
}

int	check_texture(char *sign, char *path, t_pars *pars)
{
	int	fd;

	fd = -1;
	fd = open(path, O_RDONLY, 0644);
	if (fd < 0)
		return (err_mess(ERR_IMG));
	if (assign_img(sign, path, pars) == 1)
		return (1);
	return (0);
}

int	detect_info(char **tab, t_pars *pars)
{
	if (ft_strcmp("NO", tab[0]) == 0 && count_tab(tab) == 2)
		return (check_texture(tab[0], tab[1], pars));
	else if (ft_strcmp("SO", tab[0]) == 0 && count_tab(tab) == 2)
		return (check_texture(tab[0], tab[1], pars));
	else if (ft_strcmp("WE", tab[0]) == 0 && count_tab(tab) == 2)
		return (check_texture(tab[0], tab[1], pars));
	else if (ft_strcmp("EA", tab[0]) == 0 && count_tab(tab) == 2)
		return (check_texture(tab[0], tab[1], pars));
	else if (ft_strcmp("F", tab[0]) == 0)
		check_format_rgb(tab);
	else if (ft_strcmp("C", tab[0]) == 0)
		check_format_rgb(tab);
	else
		return (err_mess(NOT_FOUND));
	return (0);
}
