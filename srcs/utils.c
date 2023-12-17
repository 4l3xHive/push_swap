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

int	ft_freeall(char **split, size_t split_i, t_stackinfo *a, t_stackinfo *b)
{
	size_t	i;

	i = 0;
	if (split)
	{
		while (i < split_i)
			free(split[i++]);
		free(split);
	}
	if (a)
	{
		free(a->nums);
		ft_lstclear(&a->stack, NULL);
	}
	if (b)
	{
		free(b->nums);
		ft_lstclear(&b->stack, NULL);
	}
	return (-1);
}

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

// Swaps the top of the stack
int	ft_swap_stack(t_list *stack)
{
	void	*temp;

	if (stack->next != NULL)
	{
		temp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = temp;
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

void	ft_printstack(t_list *a, t_list *b)
{
	t_list *curr1;
	t_list *curr2;

	curr2 = b;
	curr1 = a;
	while (curr1 || curr2)
	{
		if (curr1)
		{
			ft_printf("%d", *(int *)curr1->content);
			curr1 = curr1->next;
		}
		if (curr2)
		{
			ft_printf("      %d", *(int *)curr2->content);
			curr2 = curr2->next;
		}
		write(1, "\n", 1);
	}
	ft_printf("|a|    |b|");
}