/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:50:59 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/12 15:51:00 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
**  create new node in the beginning of the stack
*/

void	ft_dlstadd_front(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	temp = *stack;
	if (temp)
	{
		new_node->next = temp;
		temp->prev = new_node;
	}
	*stack = new_node;
}
