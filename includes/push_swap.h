/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:42:35 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/13 16:04:28 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H



# include <stdlib.h>
# include "../libftprintf/libft/libft.h"
# include "../libftprintf/mandatory/ft_printf.h"
# include <stdio.h>

typedef struct s_stackinfo
{
	t_list *stack;
	int	len;

}t_stackinfo;

int ft_swap_stack(t_stackinfo *info);
int ft_rotate_stack(t_stackinfo *info, int reverse);

#endif
