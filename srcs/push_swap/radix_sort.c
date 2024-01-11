/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:20:17 by apyykone          #+#    #+#             */
/*   Updated: 2024/01/03 16:44:42 by apyykone         ###   ########.fr       */
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

/**
 * @brief Radix sort algorithm for sorting stack of 50 or more numbers.
 * 	@param a pointer to a stack info
 * 	@param b pointer to b stack info
 */
void	ft_radix_sort(t_stackinfo *a, t_stackinfo *b)
{
	int	j;
	int	bit_size;
	int	a_len;

	bit_size = 0;
	a_len = a->curr_stack_len;
	while (a_len > 1 && ++bit_size)
		a_len /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		a_len = a->curr_stack_len;
		while (a_len-- && !ft_is_sorted_or_unique(a->stack, FALSE))
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
