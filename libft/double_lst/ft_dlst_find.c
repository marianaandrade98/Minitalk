/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:53:45 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 14:19:29 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
** returns th index of a value if it exists in stack
** if it doesn't find the value, it returns INT_MIN.
*/

int	ft_dlst_find(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (value == stack->data)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-2147483648);
}
