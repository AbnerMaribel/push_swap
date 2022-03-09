/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:44:42 by amaribel          #+#    #+#             */
/*   Updated: 2022/02/26 20:27:14 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	argv++;
	a = get_argv(argv);
	b = from_a_to_b(a);
	if (a->len < 3)
	{
		if (!sorted(a))
		{
			swap(a);
			write(1, "sa\n", 3);
		}
	}
	else
		sort_3(a);
	from_b_to_a(a, b);
	rotate_n(a, index_num(a, a->min) + 1);
	lst_free(&(a->begin_stack));
	lst_free(&(b->begin_stack));
	free(a);
	free(b);
	return (0);
}
