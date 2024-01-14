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

#include "push_swap.h"

static int	ft_print_action(int val)
{
	if (val & sa)
		return (ft_printf("sa\n"));
	else if (val & sb)
		return (ft_printf("sb\n"));
	else if (val & ss)
		return (ft_printf("ss\n"));
	else if (val & pa)
		return (ft_printf("pa\n"));
	else if (val & pb)
		return (ft_printf("pb\n"));
	else if (val & ra)
		return (ft_printf("ra\n"));
	else if (val & rb)
		return (ft_printf("rb\n"));
	else if (val & rr)
		return (ft_printf("rr\n"));
	else if (val & rra)
		return (ft_printf("rra\n"));
	else if (val & rrb)
		return (ft_printf("rrb\n"));
	else if (val & rrr)
		return (ft_printf("rrr\n"));
	return (ft_printf("\n"));
}

/**
 * @brief Swaps the first two elements of a stack.
 * @param info pointer to a stack info
 * @param swap_a if TRUE, swaps stack a, else swaps stack b
 * @param swap_both if TRUE, swaps both stacks
 */
int	ft_swap(t_stackinfo *info, int swap_a, int swap_both)
{
	t_helper	temp;
	t_list		*stack;

	stack = info->stack;
	if (stack->next != NULL)
	{
		temp.tmp_c = stack->content;
		temp.tmp_idx = stack->index;
		stack->content = stack->next->content;
		stack->index = stack->next->index;
		stack->next->index = temp.tmp_idx;
		stack->next->content = temp.tmp_c;
		if (swap_a)
			return (ft_print_action(sa));
		if (swap_both)
			return (ft_print_action(ss));
		return (ft_print_action(sb));
	}
	return (0);
}

/**
 * @brief Pushes the first element of stack to the other stack.
 * @param a pointer to a stack info
 * @param b pointer to b stack info
 * @param push_a if TRUE, pushes a, FALSE pushes b
 */
int	ft_push(t_stackinfo *a, t_stackinfo *b, int push_a)
{
	t_list	*temp;
	int		action;

	action = 0;
	if (push_a && b->stack)
	{
		temp = b->stack->next;
		ft_lstadd_front(&a->stack, b->stack);
		b->stack = temp;
		action = pa;
	}
	else if (!push_a && a->stack)
	{
		temp = a->stack->next;
		ft_lstadd_front(&b->stack, a->stack);
		a->stack = temp;
		action = pb;
	}
	a->curr_stack_len = ft_lstsize(a->stack);
	b->curr_stack_len = ft_lstsize(b->stack);
	return (ft_print_action(action));
}

static void	ft_reverse_shift(t_stackinfo *info, t_helper *r)
{
	r->current = ft_lstlast(info->stack);
	r->tmp_c = r->current->content;
	r->tmp_idx = r->current->index;
	while (r->current != info->stack)
	{
		r->prev = info->stack;
		while (r->prev->next != r->current)
			r->prev = r->prev->next;
		r->current->content = r->prev->content;
		r->current->index = r->prev->index;
		r->current = r->prev;
	}
	info->stack->content = r->tmp_c;
	info->stack->index = r->tmp_idx;
}

/**
 * @brief Rotates the stack by either way
 * @param info pointer to a stack info
 * @param reverse if TRUE, rotates the stack in reverse
 * @param rotate_a if TRUE, rotates a, else rotates b
 */
int	ft_rotate(t_stackinfo *info, int reverse, int rotate_a)
{
	t_helper	r;

	if (reverse)
		ft_reverse_shift(info, &r);
	else
	{
		r.current = info->stack;
		r.tmp_c = r.current->content;
		r.tmp_idx = r.current->index;
		while (r.current->next != NULL)
		{
			r.current->content = r.current->next->content;
			r.current->index = r.current->next->index;
			r.current = r.current->next;
		}
		r.current->content = r.tmp_c;
		r.current->index = r.tmp_idx;
	}
	if (reverse && rotate_a)
		return (ft_print_action(rra));
	else if (!reverse && !rotate_a)
		return (ft_print_action(rb));
	else if (reverse && !rotate_a)
		return (ft_print_action(rrb));
	return (ft_print_action(ra));
}
