/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_has_bigger.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:41:16 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/12 17:51:14 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
** checks if the stack has a bigger number than the value
*/

int	ft_dlst_has_bigger(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->data > value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
