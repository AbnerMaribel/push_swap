/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:41:38 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/20 23:19:03 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(*(array + i));
		i++;
	}
	free(array);
}

int	len_arr(char **array)
{
	int	i;

	i = 0;
	while (*(array + i))
		i++;
	return (i);
}

int	size_array(char **argv)
{
	int		i;
	int		n;
	int		size;
	char	**array;

	i = 0;
	size = 0;
	while (*(argv + i))
	{
		array = ft_split(*(argv + i), ' ');
		if (!array || !*array)
			error_exit();
		n = len_arr(array);
		ft_free_array(array, n);
		size = size + n;
		i++;
	}
	return (size);
}

t_stack	*arr_to_list(int *array, int len)
{
	int		i;
	t_list	*new;
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		error_exit();
	new = lst_new(*array);
	a->begin_stack = new;
	a->len = len;
	i = 1;
	while (i < len)
	{
		new = lst_add_next(new, *(array + i));
		i++;
	}
	sorting_array(array, len);
	check_repeats(array, len);
	a->min = array[0];
	a->mid = array[len / 2];
	a->max = array[len - 1];
	return (a);
}

t_stack	*get_argv(char **argv)
{
	int		len;
	int		i;
	char	**array;
	int		*int_arr;
	t_stack	*a;

	len = 0;
	int_arr = (int *)malloc(size_array(argv) * sizeof(int));
	while (*argv)
	{
		array = ft_split(*(argv++), ' ');
		if (!array || !*array)
			error_exit();
		i = 0;
		while (*(array + i))
		{
			*(int_arr + len + i) = ft_atoi(*(array + i));
			i++;
		}
		ft_free_array(array, len_arr(array));
		len = len + i;
	}
	a = arr_to_list(int_arr, len);
	free(int_arr);
	return (a);
}
