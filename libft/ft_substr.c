/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:33:56 by mandrade          #+#    #+#             */
/*   Updated: 2021/02/24 16:58:49 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		p = malloc(sizeof(char));
		if (!p)
			return (0);
		*p = '\0';
		return (p);
	}
	if (s_len < len)
		return (ft_strdup(s + start));
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (start < s_len && i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
