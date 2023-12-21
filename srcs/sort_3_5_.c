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

void	ft_sort_3(t_stackinfo *a)
{
	t_list	*s;

	s = a->stack;
	if (ft_intcmp(s->content, s->next->content) > 0
		&& ft_intcmp(s->next->next->content, s->next->content) > 0
		&& ft_intcmp(s->next->next->content, s->content))
		ft_exit(NULL, a, NULL, ft_swap(a, TRUE, FALSE) + pf_check);
	if (ft_intcmp(s->content, s->next->content) > 0
		&& ft_intcmp(s->next->content, s->next->next->content) > 0
		&& ft_intcmp(s->content, s->next->next->content) > 0)
	{
		ft_exit(NULL, a, NULL, ft_swap(a, TRUE, FALSE) + pf_check);
		ft_exit(NULL, a, NULL, ft_rotate(a, TRUE, TRUE) + pf_check);
	}
	 if (ft_intcmp(s->content, s->next->content) > 0
		&& ft_intcmp(s->next->content, s->next->next->content)> 0
		&& ft_intcmp(s->content, s->next->next->content) > 0)
		ft_exit(NULL, a, NULL, ft_rotate(a, TRUE, TRUE) + pf_check);
}

// Rotates stack 2times in choosed direction
void	ft_rotate_stack_radix(t_stackinfo *a, t_stackinfo *b, int rotate_a,
		int rev)
{
	if (rotate_a)
	{
		ft_exit(NULL, a, b, ft_rotate(a, rev, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a, rev, TRUE) + pf_check);
	}
	else
	{
		ft_exit(NULL, a, b, ft_rotate(b, rev, FALSE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(b, rev, FALSE) + pf_check);
	}
}

void	ft_push_largest_to_b(t_stackinfo *a, t_stackinfo *b)
{
	t_list	*current;
	t_index	i;

	ft_init_all(NULL, NULL, &i);
	current = a->stack;
	while (current)
	{
		if (ft_intcmp(current->content, &i.largest_content))
		{
			i.largest_content = *(int *)current->content;
			i.largest_index = i.i;
			printf("LARGEST C%d LARGEST I %d \n", i.largest_content,
				i.largest_index);
		}
		current = current->next;
		i.i++;
	}
	while (ft_intcmp(a->stack->content, &i.largest_content) != 0)
	{
		if (i.largest_index == 1)
			ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE) + pf_check);
		else if (i.largest_index == 2)
		{
			ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
			ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE) + pf_check);
		}
		else
			ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
	}
	ft_exit(NULL, a, b, ft_push(a, b, FALSE) + pf_check);
	ft_printstack(a->stack, b->stack);
}

/* Sort stack of 5 */
void	ft_sort_5(t_stackinfo *a, t_stackinfo *b)
{
	size_t	full_len;

	full_len = a->curr_stack_len;
	while (a->curr_stack_len > full_len / 2)
		ft_push_largest_to_b(a, b);
	/*
	if (ft_intcmp(b->stack->next->content, b->stack->content))
		ft_exit(NULL, a, b, ft_swap(b, FALSE, FALSE) + pf_check);
	ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
	ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
	ft_printstack(a->stack, b->stack);
	*/
}
