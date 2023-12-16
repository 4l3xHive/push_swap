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
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stackinfo
{
	t_list		*stack;
	size_t		stack_len;
	int			*nums;
}			t_stackinfo;

int			ft_swap_stack(t_list *stack);
void		ft_rotate_stack(t_stackinfo *info, int reverse);
void		ft_push_stack(t_list **a, t_list **b, int push_a);
void		ft_printstack(t_list *stack1, t_list *stack2);
int 		ft_is_stack_sorted(t_list *stack);
int 		ft_freeall(char **split, int split_i, t_stackinfo *info);
#endif
