/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:14:36 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/20 23:12:37 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_list	*tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->begin_stack;
	lst_n_elem(stack, stack->len)->next = tmp;
	stack->begin_stack = tmp->next;
	tmp->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	t_list	*lst;
	t_list	*tmp;

	if (stack->len < 2)
		return ;
	lst = lst_n_elem(stack, stack->len - 1);
	tmp = lst->next;
	lst->next = NULL;
	tmp->next = (stack->begin_stack);
	stack->begin_stack = tmp;
}

void	push(t_stack *from, t_stack *to)
{
	t_list	*tmp;

	if (from->len == 0)
		return ;
	tmp = from->begin_stack;
	from->begin_stack = tmp->next;
	tmp->next = to->begin_stack;
	to->begin_stack = tmp;
	from->len--;
	to->len++;
}

void	swap(t_stack *stack)
{
	t_list	*tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->begin_stack->next;
	stack->begin_stack->next = stack->begin_stack->next->next;
	tmp->next = stack->begin_stack;
	stack->begin_stack = tmp;
}
