/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:12:09 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 14:12:11 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

int	ft_dlst_median(t_stack *stack)
{
	t_stack	*dup;
	int		half;

	half = ft_dlst_size(stack) / 2;
	dup = ft_dlst_duplicate(stack);
	ft_dlst_sort(&dup);
	return (ft_dlst_get(dup, half - 1));
}
