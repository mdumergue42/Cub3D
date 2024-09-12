/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:49:16 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/12 16:58:29 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_pars
{
	int	f_color;
	int	c_color;
	t_coord	coor;
}	t_pars;

//check_arg.c
int	check_err_arg(int ac, char **av);
int	check_format_file(char *file);

//check_map.c
int	err_not_close(char after, char before, char down, char up);
int	actual_char(char actual);
int	check_map_close(char **map);
int	count_player(char **map);
int	check_char_map(char **map);

//principal_pars.c
int	verif_info_map(char *av);
int	verif_all_map(char **map);
char	**parse_map(char *map);

//mess_error.c in utils
int	err_mess(char *str);

//parse_utils.c
char	**info_map(char **file);
void	convert_white_s(char *str);
int	verif_char(char c);
#endif
