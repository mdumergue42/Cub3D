/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/28 20:12:50 by madumerg         ###   ########.fr       */
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
	int		i;

	i = 0;
	pars = init_pars();
	if (basics_check(ac, av, &pars) == 1)
		return (1);
	printf ("f color %d\n", pars.f_color);
	printf ("c color %d\n", pars.c_color);
	printf ("x = %d\n", pars.coor.x);
	printf ("y = %d\n", pars.coor.y);
	printf ("no_png --> %s\n", pars.no_png);
	printf ("so_png --> %s\n", pars.so_png);
	printf ("we_png --> %s\n", pars.we_png);
	printf ("ea_png --> %s\n", pars.ea_png);
	while (pars.map[i])
		printf("|%s|\n", pars.map[i++]);
	free_pars(&pars);
	return (0);
}
