/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:51:12 by madumerg          #+#    #+#             */
/*   Updated: 2024/09/04 15:59:19 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	free(s1);
	str[i] = '\0';
	return (str);
}

char	ft_end_of_line(char *line, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		i++;
		while (line[i])
		{
			buffer[j] = line[i];
			i++;
			j++;
		}
		buffer[j] = '\0';
		line[i - j] = '\0';
		return (1);
	}
	return (0);
}

char	*ft_verif(char **buffer, char *line)
{
	free(*buffer);
	*buffer = NULL;
	if (line[0] != '\0')
		return (line);
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			read_nb;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_calloc(1, 1);
	if (!buffer)
		buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (buffer && line)
	{
		line = ft_strjoin_gnl(line, buffer);
		if (!line)
			return (NULL);
		if (ft_end_of_line(line, buffer) == 1)
			return (line);
		read_nb = read(fd, buffer, BUFFER_SIZE);
		if (read_nb < 1)
			return (ft_verif(&buffer, line));
		buffer[read_nb] = '\0';
	}
	return (NULL);
}
