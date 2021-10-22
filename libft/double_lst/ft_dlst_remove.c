/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:13:39 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/18 19:22:39 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
** frees the memory of the element's content, making its previous
** element point to its next and its next point to its previous
** it also frees the element
*/

void	ft_dlst_remove(t_stack **stack)
{
	t_stack	*temporary;

	if (!stack)
		return ;
	temporary = *stack;
	if (temporary->next)
		temporary->next->prev = temporary->prev;
	if (temporary->prev)
		temporary->prev->next = temporary->next;
	if (temporary->prev)
		*stack = temporary->prev;
	else
		*stack = temporary->next;
	free(temporary);
}
