/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:37:10 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/29 20:34:58 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_tab(char **tab)
{
	char	**tmp;

	tmp = tab;
	while (tmp && *tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(tab);
	tab = NULL;
}

void	free_pars(t_pars *pars)
{
	if (pars->no_png)
		free(pars->no_png);
	if (pars->so_png)
		free(pars->so_png);
	if (pars->we_png)
		free(pars->we_png);
	if (pars->ea_png)
		free(pars->ea_png);
	if (pars->map)
		free_tab(pars->map);
}
