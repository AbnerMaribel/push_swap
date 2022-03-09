/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:43:41 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/18 12:12:18 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_1(t_stack *a, t_stack *b, t_commands move)
{
	commands_n(a, rotate, move.ra);
	commands_n(b, rotate, move.rb);
	if (move.ra <= move.rb)
	{
		ft_write_n("rr\n", move.ra);
		ft_write_n("rb\n", move.rb - move.ra);
	}
	else
	{
		ft_write_n("rr\n", move.rb);
		ft_write_n("ra\n", move.ra - move.rb);
	}
	push(b, a);
	write(1, "pa\n", 3);
}

void	move_2(t_stack *a, t_stack *b, t_commands move)
{
	commands_n(a, rotate, move.ra);
	ft_write_n("ra\n", move.ra);
	commands_n(b, reverse_rotate, move.rrb);
	ft_write_n("rrb\n", move.rrb);
	push(b, a);
	write(1, "pa\n", 3);
}

void	move_3(t_stack *a, t_stack *b, t_commands move)
{
	commands_n(a, reverse_rotate, move.rra);
	ft_write_n("rra\n", move.rra);
	commands_n(b, rotate, move.rb);
	ft_write_n("rb\n", move.rb);
	push(b, a);
	write(1, "pa\n", 3);
}

void	move_4(t_stack *a, t_stack *b, t_commands move)
{
	commands_n(a, reverse_rotate, move.rra);
	commands_n(b, reverse_rotate, move.rrb);
	if (move.rra <= move.rrb)
	{
		ft_write_n("rrr\n", move.rra);
		ft_write_n("rrb\n", move.rrb - move.rra);
	}
	else
	{
		ft_write_n("rrr\n", move.rrb);
		ft_write_n("rra\n", move.rra - move.rrb);
	}
	push(b, a);
	write(1, "pa\n", 3);
}
