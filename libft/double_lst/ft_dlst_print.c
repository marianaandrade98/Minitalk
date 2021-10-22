/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:13:31 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 14:13:33 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
** prints all data from the stack
*/

void	ft_dlst_print(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	stack = ft_dlst_first(stack);
	temp = stack;
	while (temp)
	{
		ft_putnbr_fd(temp->data, 1);
		if (temp->next)
			ft_putstr_fd(", ", 1);
		else
			ft_putstr_fd("\n", 1);
		temp = temp->next;
	}
}
