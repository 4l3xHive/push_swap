/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:42:35 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/13 23:33:03 by apyykone         ###   ########.fr       */
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
	t_list	*stack;
	int		stack_len;
}			t_stackinfo;

int			ft_swap_stack(t_stackinfo *info);
void		ft_rotate_stack(t_stackinfo *info, int reverse);
void		ft_push_stack(t_list **a, t_list **b, int push_a);
void		ft_printstack(t_list *stack);
#endif
