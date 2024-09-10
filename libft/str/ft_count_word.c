/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 00:04:58 by madumerg          #+#    #+#             */
/*   Updated: 2024/05/29 00:05:09 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str || !str[0])
		return (0);
	if (str[i++] != sep)
		count++;
	while (str[i])
	{
		if (str[i - 1] == sep && str[i] != sep)
			count++;
		i++;
	}
	return (count);
}
