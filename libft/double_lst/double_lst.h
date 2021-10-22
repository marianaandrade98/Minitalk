/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:03:04 by mandrade          #+#    #+#             */
/*   Updated: 2021/10/13 14:11:37 by mandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LST_H
# define DOUBLE_LST_H

# include "../libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_dlst_first(t_stack *stack);
t_stack	*ft_dlst_last(t_stack *stack);
t_stack	*ft_dlst_new(int content);
int		ft_dlst_size(t_stack *stack);
void	ft_dlstadd_back(t_stack **stack, t_stack *new_node);
void	ft_dlstadd_front(t_stack **stack, t_stack *new_node);
int		ft_dlstis_dup(t_stack *stack);
int		ft_dlstis_sorted(t_stack *stack);
int		ft_dlst_max(t_stack *stack);
int		ft_dlst_min(t_stack *stack);
void	ft_dlst_remove(t_stack **stack);
void	ft_dlst_clear(t_stack **stack);
void	ft_dlst_print(t_stack *stack);
t_stack	*ft_dlst_duplicate(t_stack *stack);
int		ft_dlst_find(t_stack *stack, int value);
int		ft_dlst_get(t_stack *stack, int position);
int		ft_dlst_has_bigger(t_stack *stack, int value);
int		ft_dlst_median(t_stack *stack);
void	ft_dlst_sort(t_stack **stack);
t_stack	*ft_dlst_split(t_stack *head);
t_stack	*ft_merge_sort(t_stack *first, t_stack *second);

#endif