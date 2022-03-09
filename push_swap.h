/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 03:45:00 by amaribel          #+#    #+#             */
/*   Updated: 2022/01/20 23:20:28 by amaribel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_commands
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	f1;
	int	f2;
	int	f3;
	int	f4;
}	t_commands;

typedef struct s_list
{
	int				val;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*begin_stack;
	int		min;
	int		mid;
	int		max;
	int		len;
}	t_stack;

t_stack			*get_argv(char **argv);
void			ft_free_array(char **array, int len);
int				len_arr(char **array);
int				size_array(char **argv);
t_stack			*arr_to_list(int *array, int len);
void			move_1(t_stack *a, t_stack *b, t_commands move);
void			move_2(t_stack *a, t_stack *b, t_commands move);
void			move_3(t_stack *a, t_stack *b, t_commands move);
void			move_4(t_stack *a, t_stack *b, t_commands move);
int				sorted(t_stack *a);
void			change_stack(t_stack *stack);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
void			sorting_array(int *n, int len);
void			sort_3(t_stack *a);
void			sort_3_part2(t_stack *a, int a1, int a2, int a3);
void			error_exit(void);
//long int		get_nbr(char *nptr);
void			check_repeats(int *arr, int len);
int				index_num(t_stack *stack, int num);
int				position(t_stack *stack, int num);
t_commands		get_move(int pos_a, int pos_b, int len_a, int len_b);
t_commands		min_move(t_stack *a, t_stack *b);
void			from_b_to_a(t_stack *a, t_stack *b);
t_stack			*from_a_to_b(t_stack *a);
void			move_to_b(t_stack *a, t_stack *b, int mid);
void			rotate_n(t_stack *stack, int n);
void			commands_n(t_stack *stack, void (*f)(t_stack *), int n);
void			ft_write_n(char *str, int n);
t_list			*lst_new(int val);
t_list			*lst_add_next(t_list *lst, int val);
t_list			*lst_n_elem(t_stack *stack, int n);
void			lst_delone(t_list *lst);
void			lst_free(t_list **lst);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
void			push(t_stack *from, t_stack *to);
void			swap(t_stack *stack);
void			push_swap(t_stack *a, t_stack *b);
void			push_swap2(t_stack *a, t_stack *b, char *line);

#endif