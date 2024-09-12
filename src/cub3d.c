/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:58:27 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/12 16:56:30 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "parsing.h"

t_pars	init_pars(void)
{
	t_pars	new;

	new = ft_calloc(sizeof(t_pars));
	if (!new)
		return (NULL);
	new->f_color = 0;
	new->c_color = 0;
	new->coor->x = 0;
	new->coor->y = 0
	return (new);
}

int	main(int ac, char **av)
{
	t_pars	pars;

	pars = init_pars(void);
	if (check_err_arg(ac, av) == 1)
		return (1);
	if (verif_info_map(av[1], &pars) == 1)
		return (1);
	return (0);
}
