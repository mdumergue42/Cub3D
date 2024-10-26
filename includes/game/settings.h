/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:06:39 by adjoly            #+#    #+#             */
/*   Updated: 2024/10/23 11:18:38 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SETTINGS_H
# define SETTINGS_H

// Key code
# define ESCAPE_KEY 41
# define W_KEY 26
# define S_KEY 22
# define A_KEY 4
# define D_KEY 7

# define WHITE 0xFFFFFFFF
# define WINDOW_Y 900
# define WINDOW_X 1600
# define PLAYER_ROT_SPEED (2 * M_PI) / 128
# define PLAYER_SPEED 3
# define MAP_CHUNK_SIZE 64
# define RAY_SIZE 2
# define FOV ( 60 * (M_PI / 180) )

#endif
