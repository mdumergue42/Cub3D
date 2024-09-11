/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:01:05 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/11 14:54:17 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "mess_err.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int	check_format_file(char *file);
int	check_err_arg(int argc, char **argv);

char	**parse_map(char *map);
int	err_mess(char *str);

int	verif_all_map(char **map);
int	verif_char(char c);
int	check_char_map(char **map);
void	convert_white_s(char *str);
#endif
