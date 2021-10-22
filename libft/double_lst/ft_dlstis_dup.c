/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstis_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:52:57 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 10:22:02 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
**  checks if there is a duplicate number
*/

int	ft_dlstis_dup(t_stack *stack)
{
	t_stack	*sorted;

	sorted = ft_dlst_duplicate(stack);
	ft_dlst_sort(&sorted);
	while (sorted->next)
	{
		if (sorted->data == sorted->next->data)
			return (1);
		sorted = sorted->next;
	}
	ft_dlst_clear(&sorted);
	return (0);
}
