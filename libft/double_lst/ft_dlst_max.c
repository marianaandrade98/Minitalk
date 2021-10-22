/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:12:52 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 14:12:53 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
**  finds the larger number
*/

int	ft_dlst_max(t_stack *stack)
{
	int	max;

	stack = ft_dlst_first(stack);
	max = stack->data;
	while (stack)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}
