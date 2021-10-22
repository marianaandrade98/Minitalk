/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:09:09 by mandrade          #+#    #+#             */
/*   Updated: 2021/02/12 21:26:08 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	d;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	d = ft_strlen(dst);
	s = 0;
	while (src[s] != '\0' && d + 1 < dstsize)
		dst[d++] = src[s++];
	dst[d] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[s]));
}
