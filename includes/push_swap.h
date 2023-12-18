/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:42:35 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/15 01:45:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR 1
# define SUCCESS 0
# define TRUE 1
# define FALSE 0

# include "../libftprintf/libft/libft.h"
# include "../libftprintf/mandatory/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

enum		e_action
{
	pf_err = 404,
	pf_check = 405,
	pf_callback1 = 407,
	pf_callback2 = 408,
	sa = 1,
	sb = 2,
	ss = 4,
	pa = 8,
	pb = 16,
	ra = 32,
	rb = 64,
	rr = 128,
	rra = 256,
	rrb = 512,
	rrr = 1024,
};

typedef struct s_stackinfo
{
	t_list	*stack;
	size_t	stack_len;
	int		*nums;
}			t_stackinfo;

// MAIN ACTIONS
int			ft_swap(t_list *stack, int swap_a, int swap_both);
int			ft_rotate(t_list *stack, int reverse, int rotate_a);
int			ft_push(t_list **a, t_list **b, int push_a);
int			ft_is_stack_sorted(t_list *stack);
void		ft_sort_3(t_stackinfo *a);
// int			ft_sort_5(t_list *a);
// UTILS
int			ft_intcmp(const void *a, const void *b);
void		ft_printstack(t_list *stack1, t_list *stack2);
int			ft_rotate_val(int reverse, int rotate_a);
int			ft_print_action(int val);
// CLEANUP
int			ft_freeall(char **split, size_t split_i, t_stackinfo *a,
				t_stackinfo *b);
void		ft_exit(const char *err_msg, t_stackinfo *a, t_stackinfo *b,
				int err);
// INITS    t_stackinfo  a = {0} ??
int			ft_check_args(char **av, t_stackinfo *info);
int			ft_init_stack_a(t_stackinfo *a);
void		ft_null_init(t_stackinfo *a, t_stackinfo *b);
#endif
