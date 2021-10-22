/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:13:46 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 14:13:48 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
**  give us the number of elements in stack
*/

int	ft_dlst_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
