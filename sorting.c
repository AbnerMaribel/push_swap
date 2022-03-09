/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:45:21 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/13 05:13:16 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_array(int *n, int len)
{
	int	i;
	int	tmp;
	int	counter;

	i = 0;
	counter = 1;
	while (counter)
	{
		counter = 0;
		while (i < (len - 1))
		{
			if (n[i] > n[i + 1])
			{
				tmp = n[i];
				n[i] = n[i + 1];
				n[i + 1] = tmp;
				counter = 1;
			}
			i++;
		}
		i = 0;
	}
}

void	sort_3_part2(t_stack *a, int a1, int a2, int a3)
{
	if (a1 > a3 && a2 < a3)
	{
		commands_n(a, reverse_rotate, 2);
		ft_write_n("rra\n", 2);
	}
	if (a1 > a3 && a2 > a1)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	if (a1 > a2 && a2 > a3)
	{
		swap(a);
		write(1, "sa\n", 3);
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	sort_3(t_stack *a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = a->begin_stack->val;
	a2 = a->begin_stack->next->val;
	a3 = a->begin_stack->next->next->val;
	if (a1 < a3 && a3 < a2)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
		swap(a);
		write(1, "sa\n", 3);
	}
	if (a1 > a2 && a1 < a3)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	sort_3_part2(a, a1, a2, a3);
	a->min = a->begin_stack->val;
	a->max = a->begin_stack->next->next->val;
}
