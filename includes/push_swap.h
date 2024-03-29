/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:42:35 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/27 23:40:05 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0

# include "libft.h"
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

typedef struct s_helper
{
	t_list	*current;
	t_list	*prev;
	void	*tmp_c;
	int		tmp_idx;
}			t_helper;

typedef struct s_index
{
	int		found_content;
	ssize_t	found_index;
	int		is_sorted;
	size_t	i;
	size_t	j;
	int		middle_index;
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

int			ft_swap(t_stackinfo *info, int swap_a, int swap_both);
int			ft_rotate(t_stackinfo *info, int reverse, int rotate_a);
int			ft_push(t_stackinfo *a, t_stackinfo *b, int push_a);
int			ft_is_sorted_or_unique(t_list *stack, int check_unique);
void		ft_sort_3(t_stackinfo *a, t_stackinfo *b);
void		ft_insertion_sort(t_stackinfo *a, t_stackinfo *b);
void		ft_radix_sort(t_stackinfo *a, t_stackinfo *b);
int			ft_intcmp(const void *a, const void *b);
int			ft_check_valid_int(const char *str);
void		ft_find_minmax_to_i_(t_stackinfo *a, t_stackinfo *b, t_index *i,
				int find_min);
void		ft_freeall(char **split, long split_i, t_stackinfo *a,
				t_stackinfo *b);
void		ft_exit(t_stackinfo *a, t_stackinfo *b, int pf);
void		ft_check_and_convert_args(char **av, t_stackinfo *a, t_index *i,
				char **nums);
void		ft_init_stack_a(t_stackinfo *a, t_index *i);
void		ft_init_helpers(t_stackinfo *a, t_index *i, t_sort3 *c);
#endif
