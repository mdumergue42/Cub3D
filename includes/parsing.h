/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:49:16 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/29 20:32:01 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "ft_printf.h"
# include "mess_err.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_pars
{
	int		f_color;
	int		c_color;
	int		color;
	char	l_player;
	t_coord	coor;
	char	*no_png;
	char	*so_png;
	char	*we_png;
	char	*ea_png;
	char	**map;
}	t_pars;

//check_arg.c
int		check_err_arg(int ac, char **av);
int		check_format_file(char *file);

//check_id_text.c
int		detect_info(char **tab, t_pars *pars);

//check_image.c
int		assign_img(char *sign, char *path, t_pars *pars);
int		check_dup_img(t_pars *pars);
int		check_texture(char *sign, char *path, t_pars *pars);

//check_map.c
int		err_not_close(char after, char before, char down, char up);
int		actual_char(char actual);
int		check_map_close(char **map);
int		check_char_map(char **map);

//check_rgb.c
int		check_format_rgb(char *sign, char **tab, t_pars *pars);

//color_utils.c
int		create_argb(int r, int g, int b);
char	*ft_strndup_color(char *src, int start, int end);
int		check_char_color(char *tab);
int		check_dup_color(t_pars *pars);

//find_player.c
int		search_letter(char **map, int i, char l);
int		count_player(char **map, t_pars *pars, int ct);

//principal_pars.c
int		verif_info_file(char *av, t_pars *pars);
int		verif_all_map(char **map, t_pars *pars);
char	**parse_file(char *map, int ct, int i);

//mess_error.c in utils
int		err_mess(char *str);

//parse_utils.c
void	info_map(char **file, char ***f_part);
int		verif_char(char c);
int		space_line(char *line);

//parse_utils_two.c
int		ft_count_line_map(char **map, int y);
void	replace_nl(char *l);
int		recup_map(char **old_map, int i, t_pars *pars);
int		all_skip(char **map, t_pars *pars);

//parse_utils_three.c
char	**alloc_map(char **old_map, int size);
char	*fill_line(char *l, int size);
int		last_first_line(char **map);

//utils.c
int		count_tab(char **tab);
void	convert_white_s(char *str);
int		longest_line(char **line);
int		count_line_file(int fd);

//clear_free.c
void	free_tab(char **tab);
void	free_pars(t_pars *pars);
#endif
