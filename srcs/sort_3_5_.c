/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:36:08 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/18 00:36:09 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SORT IF THERE IS 3 NUMBERS
void	ft_sort_3(t_stackinfo *a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = a->stack;
	second = first->next;
	third = first->next->next;
	if (ft_intcmp(first->content, second->content) && ft_intcmp(third->content,
			second->content) && ft_intcmp(third->content, first->content))
		ft_exit(NULL, a, NULL, ft_swap(first, TRUE, FALSE) + pf_check);
	if (ft_intcmp(first->content, second->content) && ft_intcmp(second->content,
			third->content) && ft_intcmp(first->content, third->content))
	{
		ft_exit(NULL, a, NULL, ft_swap(first, TRUE, FALSE) + pf_check);
		ft_exit(NULL, a, NULL, ft_rotate(first, TRUE, TRUE) + pf_check);
	}
	if (ft_intcmp(first->content, second->content) && ft_intcmp(third->content,
			second->content) && ft_intcmp(first->content, third->content))
		ft_rotate(first, FALSE, TRUE);
	if (ft_intcmp(first->content, second->content) && ft_intcmp(second->content,
			third->content) && ft_intcmp(first->content, third->content))
	{
		ft_exit(NULL, a, NULL, ft_swap(first, TRUE, FALSE) + pf_check);
		ft_exit(NULL, a, NULL, ft_rotate(first, FALSE, TRUE) + pf_check);
	}
	if (ft_intcmp(first->content, second->content) && ft_intcmp(second->content,
			third->content) && ft_intcmp(first->content, third->content))
		ft_exit(NULL, a, NULL, ft_rotate(first, TRUE, TRUE) + pf_check);
}

// Rotates stack 2times in choosed direction
void	ft_rotate_stack_radix(t_stackinfo *a, t_stackinfo *b, int rotate_a,
		int rev)
{
	if (rotate_a)
	{
		ft_exit(NULL, a, b, ft_rotate(a->stack, rev, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a->stack, rev, TRUE) + pf_check);
	}
	else
	{
		ft_exit(NULL, a, b, ft_rotate(b->stack, rev, FALSE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(b->stack, rev, FALSE) + pf_check);
	}
}

void	first_stack(t_stackinfo *a, t_stackinfo *b)
{
	t_list	*a_s;
	t_list	*b_s;

	a_s = a->stack;
	b_s = b->stack;
	if (ft_intcmp(a_s->content, b_s->content))
		ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE) + pf_check);
	else if (ft_intcmp(b_s->content, a_s->content) && ft_intcmp(b_s->content,
			a_s->next->content))
	{
		ft_exit(NULL, a, b, ft_rotate(a_s, FALSE, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a_s, TRUE, TRUE) + pf_check);
	}
	else if ((ft_intcmp(b_s->content, a_s->next->content))
		&& ft_intcmp(b_s->content, a_s->next->next->content))
	{
		ft_exit(NULL, a, b, ft_rotate(a_s, TRUE, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE) + pf_check);
		ft_rotate_stack_radix(a, b, TRUE, TRUE);
	}
	else if (ft_intcmp(b_s->content, a_s->next->next->content))
	{
		ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a_s, FALSE, TRUE) + pf_check);
	}
}

void	second_stack(t_stackinfo *a, t_stackinfo *b)
{
	t_list	*a_s;
	t_list	*b_s;

	a_s = a->stack;
	b_s = b->stack;
	{
		if (ft_intcmp(a_s->content, b_s->content))
			ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE) + pf_check);
		else if ((ft_intcmp(b_s->content, a_s->content))
			&& (ft_intcmp(a_s->next->content, b_s->content)))
		{
			ft_exit(NULL, a, b, ft_rotate(a_s, FALSE, TRUE));
			ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE));
			ft_exit(NULL, a, b, ft_rotate(a_s, TRUE, TRUE));
		}
		else if ((ft_intcmp(b_s->content, a_s->next->content))
			&& (ft_intcmp(a_s->next->next->content, b_s->content)))
		{
			ft_exit(NULL, a, b, ft_rotate(a_s, FALSE, TRUE));
			ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE));
			ft_exit(NULL, a, b, ft_swap(a_s, TRUE, FALSE));
			ft_exit(NULL, a, b, ft_rotate(a_s, TRUE, TRUE));
		}
		else if (ft_intcmp(a_s->next->next->content, b_s->content)
			&& (ft_intcmp(b_s->content, a_s->next->next->next->content)))
		{
			ft_exit(NULL, a, b, ft_rotate(a_s, TRUE, TRUE));
			ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE));
			ft_rotate_stack_radix(a, b, TRUE, FALSE);
		}
		else if (ft_intcmp(b_s->content, a_s->next->next->next->content))
		{
			ft_printstack(a_s, b_s);
			ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE) + pf_check);
			ft_exit(NULL, a, b, ft_rotate(a_s, FALSE, TRUE) + pf_check);
		}
	}
}
void	ft_sort_5(t_stackinfo *a, t_stackinfo *b)
{
	ft_push(a, b, NULL, FALSE);
	ft_push(a, b, NULL, FALSE);
	ft_sort_3(a);
	// ft_printstack(a->stack, b->stack);
	while (b->stack_len != 0)
	{
		if (a->stack_len == 3)
			first_stack(a, b);
		else if (a->stack_len == 4)
			second_stack(a, b);
	}
}