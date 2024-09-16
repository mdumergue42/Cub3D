/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/16 13:54:52 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pars	init_pars(void)
{
	t_pars	new;

	new.f_color = 0;
	new.c_color = 0;
	new.coor.x = 0;
	new.coor.y = 0;
	new.no_png = NULL;
	new.so_png = NULL;
	new.we_png = NULL;
	new.ea_png = NULL;
	return (new);
}

int	main(int ac, char **av)
{
	t_pars	pars;

	pars = init_pars();
	if (check_err_arg(ac, av) == 1)
		return (1);
	if (verif_info_file(av[1], &pars) == 1)
		printf("main\n");
	return (0);
}
