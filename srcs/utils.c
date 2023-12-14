/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:30:45 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/14 00:44:53 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swaps the top of the stack
int	ft_swap_stack(t_stackinfo *info)
{
	void	*temp;

	if (info->stack_len > 1)
	{
		temp = info->stack->content;
		info->stack->content = info->stack->next->content;
		info->stack->next->content = temp;
	}
	return (0);
}

void	ft_push_stack(t_list **a, t_list **b, int push_a)
{
	t_list	*temp;

	if (push_a && b)
	{
		temp = (*b)->next;
		ft_lstadd_front(a, *b);
		(*b) = temp;
	}
	else if (!push_a && a)
	{
		temp = (*a)->next;
		ft_lstadd_front(b, *a);
		(*a) = temp;
	}
}

// Rotates the stack either way
void	ft_rotate_stack(t_stackinfo *info, int reverse)
{
	t_list	*tail;
	t_list	*head;
	void	*tmp_c;

	if (info->stack_len > 1)
	{
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
	}
}
