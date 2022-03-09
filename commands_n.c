/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:44:10 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/13 04:07:08 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	commands_n(t_stack *stack, void (*f)(t_stack *), int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		f(stack);
		i++;
	}
}

void	rotate_n(t_stack *stack, int n)
{
	if (n - (stack->len) / 2 - (stack->len) % 2 > 0)
	{
		n = stack->len - n + 1;
		commands_n(stack, reverse_rotate, n);
		ft_write_n("rra\n", n);
	}
	else
	{
		n = n - 1;
		commands_n(stack, rotate, n);
		ft_write_n("ra\n", n);
	}
}

void	ft_write_n(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, str, ft_strlen(str));
		i++;
	}
}
