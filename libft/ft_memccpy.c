/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:48:38 by mandrade          #+#    #+#             */
/*   Updated: 2021/02/11 17:35:25 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dest && !source)
		return (0);
	while (n-- > 0)
	{
		*dest = *source;
		if (*source == (unsigned char)c)
			return (dest + 1);
		dest++;
		source++;
	}
	return (NULL);
}
