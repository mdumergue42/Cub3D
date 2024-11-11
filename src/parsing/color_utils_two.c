/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:11:11 by madumerg          #+#    #+#             */
/*   Updated: 2024/11/11 15:12:20 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	total_len(char **tab)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (tab[i])
	{
		len += ft_strlen(tab[i]);
		i++;
	}
	return (len);
}

char	*multi_join(char **tab, int ct)
{
	char	*str;
	int		t_len;
	int		i;

	i = 0;
	t_len = total_len(tab);
	str = malloc(t_len + 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (i < ct)
	{
		ft_strcat(str, tab[i]);
		i++;
	}
	return (str);
}
