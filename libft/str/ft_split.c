/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:11:54 by gadelbes          #+#    #+#             */
/*   Updated: 2024/05/29 00:04:26 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

int	ft_count_len(const char *str, char sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && str[i] != sep)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		w;
	int		l;

	i = 0;
	w = 0;
	if (!s)
		return (NULL);
	str = ft_calloc((ft_count_word((char *)s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	while (w < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		l = ft_count_len((s + i), c);
		str[w] = ft_calloc(l + 1, sizeof(char));
		if (!str[w])
			return (ft_free(str));
		ft_strlcpy(str[w], s + i, l + 1);
		w++;
		i += l;
	}
	return (str);
}
