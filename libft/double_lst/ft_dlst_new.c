/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:13:18 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 14:13:20 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_lst.h"

/*
**  create new node
*/

t_stack	*ft_dlst_new(int content)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
		return (0);
	temp->data = content;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}
