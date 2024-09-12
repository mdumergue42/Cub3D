/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:49:16 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/12 12:57:11 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

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
int	verif_all_map(char **map);
char	**parse_map(char *map);

//mess_error.c in utils
int	err_mess(char *str);

//parse_utils.c
void	convert_white_s(char *str);
int	verif_char(char c);
#endif
