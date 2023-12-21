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

// Swaps the first 2 of the stack
int	ft_swap(t_stackinfo *info, int swap_a, int swap_both)
{
	void	*temp;
	t_list	*stack;

	stack = info->stack;
	if (stack->next != NULL)
	{
		temp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = temp;
		if (swap_a)
			return (ft_print_action(sa));
		if (swap_both)
			return (ft_print_action(ss));
		return (ft_print_action(sb));
	}
	return (0);
}

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

// Rotates the stack either way
int	ft_rotate(t_stackinfo *info, int reverse, int rotate_a)
{
	t_list	*tail;
	t_list	*head;
	void	*tmp_c;

	tail = info->stack;
	if (reverse)
	{
		head = ft_lstlast(tail);
		tmp_c = head->content;
		head->content = tail->content;
		tail->content = tmp_c;
		tail = tail->next;
	}
	head = tail->next;
	while (head)
	{
		tmp_c = tail->content;
		tail->content = head->content;
		head->content = tmp_c;
		head = head->next;
		tail = tail->next;
	}
	return (ft_print_action(ft_rotate_val(reverse, rotate_a)));
}

int	ft_print_action(int val)
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

int	ft_rotate_val(int reverse, int rotate_a)
{
	if (!reverse && rotate_a)
		return (ra);
	else if (reverse && rotate_a)
		return (rra);
	else if (!reverse && !rotate_a)
		return (rb);
	else if (reverse && !rotate_a)
		return (rrb);
	return (0);
}
