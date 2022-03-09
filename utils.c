/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:45:48 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/13 05:13:22 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *a)
{
	t_list	*lst;

	lst = a->begin_stack;
	while (lst && lst->next)
	{
		if (lst->val > lst->next->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	change_stack(t_stack *stack)
{
	if ((stack->begin_stack)->val < stack->min)
		stack->min = (stack->begin_stack)->val;
	if ((stack->begin_stack)->val > stack->max)
		stack->max = (stack->begin_stack)->val;
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
