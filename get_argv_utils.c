/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:41:23 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/20 23:33:23 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

long int	get_nbr(char *n)
{
	long int	i;
	int			sign;

	i = 0;
	sign = 1;
	while (*n == ' ')
		n++;
	if (*n == '-')
	{
		sign = -1;
		n++;
	}
	else if (*n == '+')
		n++;
	if (!ft_isdigit(*n))
		error_exit();
	while (*n)
	{
		if (!ft_isdigit(*n))
			error_exit();
		i = i * 10 + (*n - 48);
		n++;
	}
	i = i * sign;
	if (i > INT32_MAX || i < INT32_MIN)
		error_exit();
	return (i);
}

void	check_repeats(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] == arr[i + 1])
			error_exit();
		i++;
	}
}
