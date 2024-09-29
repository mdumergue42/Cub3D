/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:38:32 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/29 20:36:52 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	detect_info(char **tab, t_pars *pars)
{
	if (ft_strncmp("NO", tab[0], 2) == 0 && count_tab(tab) == 2)
		return (check_texture(tab[0], tab[1], pars));
	else if (ft_strncmp("SO", tab[0], 2) == 0 && count_tab(tab) == 2)
		return (check_texture(tab[0], tab[1], pars));
	else if (ft_strncmp("WE", tab[0], 2) == 0 && count_tab(tab) == 2)
		return (check_texture(tab[0], tab[1], pars));
	else if (ft_strncmp("EA", tab[0], 2) == 0 && count_tab(tab) == 2)
		return (check_texture(tab[0], tab[1], pars));
	else if (ft_strncmp("F", tab[0], 1) == 0 && count_tab(tab) == 2)
		return (check_format_rgb("F", tab, pars));
	else if (ft_strncmp("C", tab[0], 1) == 0 && count_tab(tab) == 2)
		return (check_format_rgb("C", tab, pars));
	else
		return (err_mess(NOT_FOUND));
	return (0);
}
