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
/* PROTO FOR REVERSE IN SAME FUNCTION !!
int	ft_rotate_stack(t_stackinfo *info, int reverse)
{
	t_list  *first;
	t_list  *second;
	void    *tmp_c;
	(void)reverse;

	if (info->len > 1)
	{
		first = info->stack;
		second = first->next;
		if (reverse)
		{
			first = ft_lstlast(info->stack);
			second = info->stack;
		}
		while (second)
		{
			tmp_c = first->content;
			first->content = second->content;
			second->content = tmp_c;
			second = second->next;
			first = first->next;
		}

	}
	return (0);
	}*/
