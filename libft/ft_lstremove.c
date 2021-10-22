/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 06:58:52 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/20 06:58:55 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **lst)
{
	t_list	*temporary;

	if (!lst)
		return ;
	temporary = *lst;
	*lst = temporary->next;
	temporary->next = NULL;
	free(temporary);
}
