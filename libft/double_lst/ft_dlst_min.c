/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:13:04 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/19 19:02:42 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
**  finds the smallest number
*/

int	ft_dlst_min(t_stack *stack)
{
	int	min_value;

	min_value = stack->data;
	while (stack)
	{
		if (stack->data < min_value)
			min_value = stack->data;
		stack = stack->next;
	}
	return (min_value);
}
