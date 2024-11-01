/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:06:39 by adjoly            #+#    #+#             */
/*   Updated: 2024/11/01 15:53:20 by madumerg         ###   ########.fr       */
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
# define DEG_TO_RAD	0.0174533

# define WINDOW_H 900
# define WINDOW_W 1600
# define PLAYER_ROT_SPEED (2 * M_PI) / 128
# define PLAYER_SPEED 0.01
# define RAY_SIZE 50
# define FOV ( 60 * (M_PI / 180) )

# define CHUNK_SIZE 64

#endif
