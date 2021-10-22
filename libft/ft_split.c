/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:29:59 by mandrade          #+#    #+#             */
/*   Updated: 2021/02/23 19:33:52 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_counter(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	char	*str;
	size_t	i;

	dst = (char **)malloc(sizeof(char *) * char_counter(s, c) + 1);
	if (!s || !dst)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			str = (char *)s;
			while (*s && *s != c)
				s++;
			dst[i] = (char *)malloc(s - str + 1);
			if (!dst)
				return (0);
			ft_strlcpy(dst[i++], str, s - str + 1);
		}
		else
			s++;
	}
	dst[i] = 0;
	return (dst);
}
