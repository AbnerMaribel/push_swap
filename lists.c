/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:43:23 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/14 14:14:26 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int val)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		error_exit();
	new->val = val;
	new->next = NULL;
	return (new);
}

t_list	*lst_add_next(t_list *lst, int val)
{
	t_list	*new;

	new = lst_new(val);
	if (lst)
		lst->next = new;
	return (new);
}

t_list	*lst_n_elem(t_stack *stack, int n)
{
	t_list	*lst;

	lst = stack->begin_stack;
	while (n > 1)
	{
		lst = lst->next;
		n--;
	}
	return (lst);
}

void	lst_delone(t_list *lst)
{
	if (lst)
		free(lst);
}

void	lst_free(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			lst_delone(*lst);
			*lst = tmp;
		}
	}
}
