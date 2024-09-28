/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:38:32 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/28 17:06:14 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	else if (ft_strcmp("F", tab[0]) == 0 && count_tab(tab) == 2)
		return (check_format_rgb("F", tab, pars));
	else if (ft_strcmp("C", tab[0]) == 0 && count_tab(tab) == 2)
		return (check_format_rgb("C", tab, pars));
	else
		return (err_mess(NOT_FOUND));
	return (0);
}
