/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:30:45 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/16 15:31:18 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// Swaps the first 2 of the stack
int	ft_swap(t_stackinfo *info)
{
	void	*temp;
	t_list	*stack;

	stack = info->stack;
	if (stack->next != NULL)
	{
		temp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = temp;
	}
	return (0);
}

int	ft_push(t_stackinfo *a, t_stackinfo *b, int push_a)
{
	t_list	*temp;

	if (push_a && b->stack)
	{
		temp = b->stack->next;
		ft_lstadd_front(&a->stack, b->stack);
		b->stack = temp;
	}
	else if (!push_a && a->stack)
	{
		temp = a->stack->next;
		ft_lstadd_front(&b->stack, a->stack);
		a->stack = temp;
	}
	a->curr_stack_len = ft_lstsize(a->stack);
	b->curr_stack_len = ft_lstsize(b->stack);
	return (0);
}

static void	ft_shift_contents(t_stackinfo *info, int reverse, t_rotate *r)
{
	if (reverse)
	{
		r->current = ft_lstlast(info->stack);
		r->tmp_c = r->current->content;
		while (r->current != info->stack)
		{
			r->prev = info->stack;
			while (r->prev->next != r->current)
				r->prev = r->prev->next;
			r->current->content = r->prev->content;
			r->current = r->prev;
		}
		info->stack->content = r->tmp_c;
	}
	else
	{
		r->current = info->stack;
		r->tmp_c = r->current->content;
		while (r->current->next != NULL)
		{
			r->current->content = r->current->next->content;
			r->current = r->current->next;
		}
		r->current->content = r->tmp_c;
	}
}

int	ft_rotate(t_stackinfo *info, int reverse)
{
	t_rotate	r;

	ft_shift_contents(info, reverse, &r);
	return (0);
}
