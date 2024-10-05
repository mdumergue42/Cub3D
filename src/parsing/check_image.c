/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:44:07 by madumerg          #+#    #+#             */
/*   Updated: 2024/10/05 13:39:06 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	assign_img_two(char *sign, char *path, t_pars *pars)
{
	if (ft_strcmp("WE", sign) == 0)
	{
		if (pars->we_png == NULL)
			pars->we_png = ft_strdup(path);
		else
			return (err_mess(DUP_ACR));
	}
	else if (ft_strcmp("EA", sign) == 0)
	{
		if (pars->ea_png == NULL)
			pars->ea_png = ft_strdup(path);
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
			pars->no_png = ft_strdup(path);
		else
			return (err_mess(DUP_ACR));
	}
	else if (ft_strcmp("SO", sign) == 0)
	{
		if (pars->so_png == NULL)
			pars->so_png = ft_strdup(path);
		else
			return (err_mess(DUP_ACR));
	}
	if (assign_img_two(sign, path, pars) == 1)
		return (1);
	return (0);
}

int	format_img(char *img)
{
	int	len;

	len = ft_strlen(img) - 1;
	if (img[len] == 'g' && img[len - 1] == 'n' && \
	img[len - 2] == 'p' && img[len - 3] == '.')
		return (0);
	return (1);
}

int	check_texture(char *sign, char *path, t_pars *pars)
{
	int	fd;

	fd = -1;
	fd = open(path, O_RDONLY, 0644);
	if (fd < 0)
		return (err_mess(ERR_IMG));
	if (format_img(path) == 1)
	{
		close(fd);
		return (err_mess(WRONG_F_IMG));
	}
	if (assign_img(sign, path, pars) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
