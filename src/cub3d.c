/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/29 20:36:29 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pars	init_pars(void)
{
	t_pars	new;

	new.f_color = -1;
	new.c_color = -1;
	new.color = 0;
	new.l_player = 0;
	new.coor.x = 0;
	new.coor.y = 0;
	new.no_png = NULL;
	new.so_png = NULL;
	new.we_png = NULL;
	new.ea_png = NULL;
	new.map = NULL;
	return (new);
}

int	basics_check(int ac, char **av, t_pars *pars)
{
	if (check_err_arg(ac, av) == 1)
		return (1);
	if (verif_info_file(av[1], pars) == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_pars	pars;

	pars = init_pars();
	if (basics_check(ac, av, &pars) == 1)
	{
		free_pars(&pars);
		return (1);
	}
	free_pars(&pars);
	return (0);
}
