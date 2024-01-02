/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:20:17 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/31 00:20:19 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort_stack_b(t_stackinfo *a, t_stackinfo *b, int bit_size,
		int j)
{
	int	b_size;

	b_size = b->curr_stack_len;
	while (b_size-- && j <= bit_size && !ft_is_sorted_or_unique(a->stack,
			FALSE))
	{
		if (((b->stack->index >> j) & 1) == 0)
			ft_exit(a, b, ft_rotate(b, FALSE, FALSE));
		else
			ft_exit(a, b, ft_push(a, b, TRUE));
	}
	if (ft_is_sorted_or_unique(a->stack, FALSE))
		while (b->stack)
			ft_exit(a, b, ft_push(a, b, TRUE));
}

void	ft_radix_sort(t_stackinfo *a, t_stackinfo *b)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = a->curr_stack_len;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = a->curr_stack_len;
		while (size-- && !ft_is_sorted_or_unique(a->stack, FALSE))
		{
			if (((a->stack->index >> j) & 1) == 0)
				ft_exit(a, b, ft_push(a, b, FALSE));
			else
				ft_exit(a, b, ft_rotate(a, FALSE, TRUE));
		}
		radix_sort_stack_b(a, b, bit_size, j + 1);
	}
	while (b->curr_stack_len)
		ft_exit(a, b, ft_push(a, b, TRUE));
}
