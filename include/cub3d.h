/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:01:05 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/07 17:48:56 by madumerg         ###   ########.fr       */
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

int	check_format_file(char *file);
int	check_err_arg(int argc, char **argv);

int	err_mess(char *str);

#endif
