/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:41:07 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/20 23:15:06 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_num(t_stack *stack, int num)
{
	int		n;
	t_list	*lst;

	n = 0;
	lst = stack->begin_stack;
	while (lst && lst->val != num)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

int	position(t_stack *stack, int num)
{
	int		n;
	t_list	*lst;

	n = 0;
	if (num > stack->max)
		return (index_num(stack, stack->max) + 1);
	else if (num < stack->min)
		return (index_num(stack, stack->min));
	lst = stack->begin_stack;
	if (lst->val > num && (lst_n_elem(stack, stack->len))->val < num)
		return (0);
	while (lst && lst->next && !(lst->val < num && (lst->next)->val > num))
	{
		n++;
		lst = lst->next;
	}
	return (++n);
}

t_commands	get_move(int pos_a, int pos_b, int len_a, int len_b)
{
	t_commands	movements;

	movements.ra = pos_a;
	movements.rb = pos_b;
	movements.rra = len_a - pos_a;
	movements.rrb = len_b - pos_b;
	movements.f1 = ft_max(movements.ra, movements.rb);
	movements.f2 = movements.ra + movements.rrb;
	movements.f3 = movements.rra + movements.rb;
	movements.f4 = ft_max(movements.rra, movements.rrb);
	return (movements);
}

t_commands	min_move(t_stack *a, t_stack *b)
{
	int			min;
	int			pos_b;
	t_list		*lst_b;
	t_commands	move;
	t_commands	min_move;

	min = a->len + b->len;
	pos_b = 0;
	lst_b = b->begin_stack;
	min_move = get_move(0, 0, 0, 0);
	while (lst_b)
	{
		move = get_move(position(a, lst_b->val), pos_b,
				a->len, b->len);
		if (min > ft_min(ft_min(move.f1, move.f2), ft_min(move.f3, move.f4)))
		{
			min_move = move;
			min = ft_min(ft_min(move.f1, move.f2), ft_min(move.f3, move.f4));
		}
		pos_b++;
		lst_b = lst_b->next;
	}
	return (min_move);
}

void	from_b_to_a(t_stack *a, t_stack *b)
{
	int			min;
	t_commands	move;

	while (b->begin_stack)
	{
		move = min_move(a, b);
		min = ft_min(ft_min(move.f1, move.f2), ft_min(move.f3, move.f4));
		if (move.f1 == min)
			move_1(a, b, move);
		else if (move.f2 == min)
			move_2(a, b, move);
		else if (move.f3 == min)
			move_3(a, b, move);
		else if (move.f4 == min)
			move_4(a, b, move);
		change_stack(a);
	}
}
