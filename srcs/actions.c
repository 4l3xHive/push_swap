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

// Checks that if the stack is sorted
int	ft_is_stack_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

// Swaps the first 2 of the stack
int	ft_swap(t_list *stack, int swap_a, int swap_both)
{
	void	*temp;

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

int	ft_push(t_stackinfo *a, t_stackinfo *b, t_list **curr, int push_a)
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
		if (curr)
			*curr = a->stack;
	}
	else if (!push_a && a->stack)
	{
		temp = a->stack->next;
		ft_lstadd_front(&b->stack, a->stack);
		a->stack = temp;
		action = pb;
		if (curr)
			*curr = b->stack;
	}
	a->stack_len = ft_lstsize(a->stack);
	b->stack_len = ft_lstsize(b->stack);
	return (ft_print_action(action));
}

// Rotates the stack either way
int	ft_rotate(t_list *stack, int reverse, int rotate_a)
{
	t_list	*tail;
	t_list	*head;
	void	*tmp_c;

	tail = stack;
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
