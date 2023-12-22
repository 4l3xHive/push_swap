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

void	ft_sort_3(t_stackinfo *a, t_stackinfo *b)
{
	t_sort3	c;

	ft_init_all(a, NULL, NULL, &c);
	if (c.first > c.second && c.second > c.third)
	{ // Case: c, b, a
		ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
	}
	else if (c.first > c.second && c.first < c.third) // Case: b, a, c
		ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE) + pf_check);
	else if (c.second > c.first && c.second > c.third && c.first < c.third)
	{ // Case: a, c, b
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE) + pf_check);
	}
	else if (c.second < c.first && c.second < c.third && c.first > c.third)
		// Case: c, a, b
		ft_exit(NULL, a, b, ft_rotate(a, FALSE, TRUE) + pf_check);
	else if (c.third > c.first && c.third < c.second)
	{ // Case: a,c, b
		ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a, FALSE, TRUE) + pf_check);
	}
	// No action needed for the sorted case: a, b, c
}

void	ft_push_smallest_to_b(t_stackinfo *a, t_stackinfo *b, size_t middle)
{
	t_list	*current;
	t_index	i;

	ft_init_all(NULL, NULL, &i, NULL);
	current = a->stack;
	while (current)
	{
		if (ft_intcmp(current->content, &i.smallest_content) < 0)
		{
			i.smallest_content = *(int *)current->content;
			i.smallest_index = i.i;
		}
		current = current->next;
		i.i++;
	}
	while (ft_intcmp(a->stack->content, &i.smallest_content) != 0)
	{
		if (i.smallest_index == 1)
			ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE) + pf_check);
		else if (i.smallest_index > middle)
			ft_exit(NULL, a, b, ft_rotate(a, FALSE, TRUE) + pf_check);
		else
			ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
	}
	ft_exit(NULL, a, b, ft_push(a, b, FALSE) + pf_check);
}

/* Sort stack of 5 */
void	ft_sort_stack(t_stackinfo *a, t_stackinfo *b)
{
	size_t	middle_ind;

	ft_printstack(a->stack, b->stack);
	while (!ft_is_stack_sorted(a->stack) && a->curr_stack_len > 3)
	{
		middle_ind = a->curr_stack_len / 2 + 1;
		ft_push_smallest_to_b(a, b, middle_ind);
	}
	ft_sort_3(a, b);
	while (b->stack)
		ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
	ft_printstack(a->stack, b->stack);
}
