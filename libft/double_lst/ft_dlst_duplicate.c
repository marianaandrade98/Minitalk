/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_duplicate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:55:54 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/12 16:51:32 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
**  copies a stack and creates a duplicate
*/

t_stack	*ft_dlst_duplicate(t_stack *stack)
{
	t_stack	*dup;
	t_stack	*new_node;

	dup = 0;
	while (stack)
	{
		new_node = ft_dlst_new(stack->data);
		if (!new_node)
		{
			ft_dlst_clear(&dup);
			return (0);
		}
		ft_dlstadd_back(&dup, new_node);
		stack = stack->next;
	}
	return (dup);
}
