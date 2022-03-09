/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:41:51 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/14 03:03:36 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack *a, t_stack *b, int mid)
{
	while (a->len > 3)
	{
		if (a->begin_stack->val <= mid)
		{
			push(a, b);
			write(1, "pb\n", 3);
			rotate(b);
			write(1, "rb\n", 3);
		}
		else
		{
			push(a, b);
			write(1, "pb\n", 3);
		}
	}
}

t_stack	*from_a_to_b(t_stack *a)
{
	int		i;
	int		n;
	t_stack	*b;

	i = 0;
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		error_exit();
	b->begin_stack = NULL;
	b->len = 0;
	n = a->len;
	if (a->len < 3)
		return (b);
	else if (!sorted(a) && a->len > 3)
		move_to_b(a, b, a->mid);
	return (b);
}
