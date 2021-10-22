/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:06:03 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/12 17:06:05 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
**  takes us back to the first node
*/

t_stack	*ft_dlst_first(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}
