/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:12:27 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 14:19:39 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
** returns the value of a position in stack if it exists.
** if the position is bigger than the size of the stack,
**     the function returns INT_MIN
*/

int	ft_dlst_get(t_stack *stack, int position)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i == position)
			return (stack->data);
		stack = stack->next;
		i++;
	}
	return (-2147483648);
}
