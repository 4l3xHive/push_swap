/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusousa <gusousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:23:15 by gusousa           #+#    #+#             */
/*   Updated: 2022/11/17 09:26:07 by gusousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_my_b(t_stackinfo *a, t_stackinfo *b, int msb)
{
	size_t	i;
	//int	size_list_b;

	i = 0;
	b->curr_stack_len = ft_lstsize(b->stack);
	while (i++ < b->curr_stack_len && !ft_is_sorted_or_unique(a->stack, FALSE))
	{
		if (*(int *)b->stack->content & (1u << msb))
			ft_exit(a, b, ft_push(a, b, TRUE));
           // pa(list_a, list_b);
		else
			ft_exit(a, b, ft_rotate(b, FALSE, FALSE));
          //rb(list_b);
	}
}


void	radix_my_a(t_stackinfo *a, t_stackinfo *b, int msb)
{
	size_t	i;
	//int	size_list_a;

	i = 0;
	a->curr_stack_len = ft_lstsize(a->stack);
	while (i++ < a->curr_stack_len && !ft_is_sorted_or_unique(a->stack, FALSE))
	{
		if (*(int *)a->stack->content & (1u << msb))
			ft_exit(a, b, ft_rotate(a, FALSE, TRUE));
            //ra(list_a);
		else
			ft_exit(a, b, ft_push(a, b, FALSE));
            //pb(list_a, list_b);
	}
}

int	get_msb(t_list *list_a)
{
	int	msb;
	int	biggest;

	biggest = INT_MIN;
	while (list_a)
	{
		if (biggest < *(int *)list_a->content)
			biggest = *(int *)list_a->content;
		list_a = list_a->next;
	}
	msb = 0;
	while (biggest)
	{
		biggest = biggest >> 1;
		msb++;
	}
	return (msb);
}

void	ft_sort_big(t_stackinfo *a, t_stackinfo *b)
{
	int	pos_msb;
	int	cont;

	pos_msb = get_msb(a->stack);
	cont = pos_msb;
	while (cont)
	{
		radix_my_a(a, b, pos_msb - cont);
		cont--;
		radix_my_b(a, b, pos_msb - cont);
	}
	while (b->stack)
		ft_exit(a, b, ft_push(a, b, TRUE));
	ft_printstack(a, b);
}