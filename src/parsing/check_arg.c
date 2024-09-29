/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:33:35 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/29 20:36:43 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_err_arg(int ac, char **av)
{
	int		fd;
	int		rd;
	char	buf[10];

	if (ac != 2)
		return (err_mess(ERR_ARGS));
	if (check_format_file(av[1]) == 0)
		return (err_mess(ERR_TYPE));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (err_mess(EMPTY));
	}
	rd = read(fd, buf, 10);
	close(fd);
	return (rd);
}

int	check_format_file(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (file[len] == 'b' && file[len - 1] == 'u' && \
	file[len - 2] == 'c' && file[len - 3] == '.')
		return (1);
	return (0);
}
