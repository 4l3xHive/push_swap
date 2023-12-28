/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:40:36 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/26 19:59:00 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

typedef struct s_rotate
{
	t_list	*current;
	t_list	*prev;
	void	*tmp_c;
}			t_rotate;

typedef struct s_index
{
	int		found_content;
	ssize_t	found_index;
	int		is_sorted;
	size_t	i;

}			t_index;

typedef struct s_stackinfo
{
	t_list	*stack;
	size_t	curr_stack_len;
	int		*nums;
}			t_stackinfo;

// MAIN ACTIONS
int			ft_swap(t_stackinfo *info);
int			ft_rotate(t_stackinfo *info, int reverse);
int			ft_push(t_stackinfo *a, t_stackinfo *b, int push_a);
int			ft_is_sorted_or_unique(t_list *stack, int check_unique);

// UTILS
int			ft_strcmp(const char *s1, const char *s2);
int			ft_str_isdigit(const char *str);
int			ft_check_valid(const char *str);
long		ft_atol(const char *str);
// CLEANUP
void		ft_freeall(char **split, long split_i, t_stackinfo *a,
				t_stackinfo *b);
void		ft_exit(t_stackinfo *a, t_stackinfo *b, int pf);
// INITS    t_stackinfo  a = {0} ??
void		ft_check_args(char **av, t_stackinfo *a);

void		ft_check_and_convert_args(char **av, t_stackinfo *a, t_index *i,
				char **nums);
void		ft_init_stack_a(t_stackinfo *a, t_index *i);
void		ft_init_all(t_stackinfo *a, t_stackinfo *b, t_index *i);
#endif
