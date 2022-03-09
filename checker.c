/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:29:42 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/14 14:08:49 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap2(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp("ra\n", line, 3))
		rotate(a);
	if (!ft_strncmp("rb\n", line, 3))
		rotate(b);
	if (!ft_strncmp("rr\n", line, 3))
	{
		rotate(a);
		rotate(b);
	}
	if (!ft_strncmp("rra\n", line, 4))
		reverse_rotate(a);
	if (!ft_strncmp("rrb\n", line, 4))
		reverse_rotate(b);
	if (!ft_strncmp("rrr\n", line, 4))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp("sa\n", line, 3))
			swap(a);
		if (!ft_strncmp("sb\n", line, 3))
			swap(b);
		if (!ft_strncmp("ss\n", line, 3))
		{
			swap(a);
			swap(b);
		}
		if (!ft_strncmp("pa\n", line, 3))
			push(b, a);
		if (!ft_strncmp("pb\n", line, 3))
			push(a, b);
		push_swap2(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	argv++;
	argc--;
	a = get_argv(argv);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		error_exit();
	b->begin_stack = NULL;
	b->len = 0;
	push_swap(a, b);
	if (sorted(a) && a->len && !(b->len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lst_free(&(a->begin_stack));
	lst_free(&(b->begin_stack));
	free(a);
	free(b);
	return (0);
}
