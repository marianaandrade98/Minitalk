/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:12:52 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/19 18:59:47 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
**  finds the larger number
*/

int	ft_dlst_max(t_stack *stack)
{
	int	max_value;

	max_value = stack->data;
	while (stack)
	{
		if (stack->data > max_value)
			max_value = stack->data;
		stack = stack->next;
	}
	return (max_value);
}
