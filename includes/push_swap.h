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
# define TRUE 1
# define FALSE 0

# include "../libftprintf/libft/libft.h"
# include "../libftprintf/mandatory/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

enum		e_action
{
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

typedef struct s_index
{
	int		smallest_content;
	ssize_t	smallest_index;
	int		is_sorted;
	size_t	i;

}			t_index;

typedef struct s_sort3
{
	int		first;
	int		second;
	int		third;
}			t_sort3;

typedef struct s_stackinfo
{
	t_list	*stack;
	size_t	curr_stack_len;
	int		*nums;
}			t_stackinfo;

// MAIN ACTIONS
int			ft_swap(t_stackinfo *info, int swap_a, int swap_both);
int			ft_rotate(t_stackinfo *info, int reverse, int rotate_a);
int			ft_push(t_stackinfo *a, t_stackinfo *b, int push_a);
int			ft_is_sorted_or_unique(t_list *stack, int check_unique);
void		ft_sort_3(t_stackinfo *a, t_stackinfo *b);
void		ft_sort_stack(t_stackinfo *a, t_stackinfo *b);
// UTILS
int			ft_intcmp(const void *a, const void *b);
void		ft_printstack(t_stackinfo *a, t_stackinfo *b);
int			ft_rotate_val(int reverse, int rotate_a);
int			ft_print_action(int val);
int			ft_str_isdigit(const char *str);
int			ft_check_valid(const char *str);
long		ft_atol(const char *str);
// CLEANUP
void		ft_freeall(char **split, long split_i, t_stackinfo *a,
				t_stackinfo *b);
void		ft_exit(t_stackinfo *a, t_stackinfo *b, int pf);
// INITS    t_stackinfo  a = {0} ??
void		ft_check_args(char **av, t_stackinfo *a);
void		ft_init_stack_a(t_stackinfo *a);
void		ft_init_all(t_stackinfo *a, t_stackinfo *b, t_index *i, t_sort3 *c);
#endif
