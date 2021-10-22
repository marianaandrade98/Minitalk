/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:11:51 by mandrade          #+#    #+#             */
/*   Updated: 2021/02/11 20:33:09 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dest && !source)
		return (0);
	if (source < dest)
	{
		source += n;
		dest += n;
		while (n--)
			*--dest = *--source;
	}
	else
	{
		while (n--)
			*dest++ = *source++;
	}
	return (dst);
}
