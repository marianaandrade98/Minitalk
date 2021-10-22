/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:50:52 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/12 15:50:53 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
**  create new node in the end of the stack
*/

void	ft_dlstadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!*stack)
		*stack = new_node;
	else
	{
		last = ft_dlst_last(*stack);
		new_node->prev = last;
		last->next = new_node;
	}
}
