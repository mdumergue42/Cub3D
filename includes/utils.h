/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:03:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/06 13:21:21 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "parsing.h"
# include "game/game.h"

t_player	init_player(t_pars parsing);
t_map		init_world(t_pars parsing);
void		init_texture(t_render *render, t_pars parsing);

#endif
