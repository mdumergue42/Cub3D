/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:47:43 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/10 16:50:37 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "game.h"
# include "dda.h"

void	*get_texture(bool hor, t_render *render, t_ray *ray);
void	draw_celling(t_render *render);
void	draw_floor(t_render *render);

#endif
