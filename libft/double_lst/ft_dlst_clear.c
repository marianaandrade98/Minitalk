/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:51:57 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/12 15:52:01 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

void	ft_dlst_clear(t_stack **stack)
{
	if (!*stack)
		return ;
	while (*stack)
		ft_dlst_remove(stack);
}
