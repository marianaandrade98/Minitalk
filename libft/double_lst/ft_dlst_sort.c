/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:13:58 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 14:14:00 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

void	ft_dlst_sort(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	if (!first || first->next)
		return ;
	second = ft_dlst_split(first);
	ft_dlst_sort(&first);
	ft_dlst_sort(&second);
	*stack = ft_merge_sort(first, second);
}

/*
** iterates a stack, incrementing 'fast' and subsequently incrementing
** 'slow'. By the time the program exists with the while loop, 'slow' stack
** will have the future head of the second half stack 'second'
*/

t_stack	*ft_dlst_split(t_stack *head)
{
	t_stack	*slow;
	t_stack	*fast;
	t_stack	*temp;

	slow = head;
	fast = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	temp = slow->next;
	slow->next = 0;
	return (temp);
}

/*
** it merges stack_a with stack_b in a sorted matter, and returns the head
** of the sorted stack reference.
**		- if the first node of the first half is bigger than the first node
**		of the second half, then it calls the function itself with the first
**		half being incremented by one.
**
**		- if the first node of the second half is bigger than the first node 
**		of the first half, then it calls the function itself with the second
**		half being incremented by one.
*/

t_stack	*ft_merge_sort(t_stack *first, t_stack *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (first->data < second->data)
	{
		first->next = ft_merge_sort(first->next, second);
		first->next->prev = first;
		first->prev = 0;
		return (first);
	}
	else
	{
		second->next = ft_merge_sort(first, second->next);
		second->next->prev = second;
		second->prev = 0;
		return (second);
	}
}
