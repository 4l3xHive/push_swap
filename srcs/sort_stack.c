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

/* Works with equal values on the stack also*/
static void	ft_check_equals(t_stackinfo *a, t_stackinfo *b, t_sort3 *c)
{
	if (c->first == c->second && c->second < c->third)
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE));
	else if (c->first == c->second && c->second > c->third)
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE));
	else if (c->second == c->third && c->first < c->second)
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE));
	else if (c->second == c->third && c->first > c->second)
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE));
}

/* Sorts stack of 3 if not sorted*/
void	ft_sort_3(t_stackinfo *a, t_stackinfo *b)
{
	t_sort3	c;

	ft_init_all(a, NULL, NULL, &c);
	if (c.first > c.second && c.second > c.third)
	{
		ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE));
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE));
	}
	else if (c.first > c.second && c.first < c.third)
		ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE));
	else if (c.second > c.first && c.second > c.third && c.first < c.third)
	{
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE));
		ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE));
	}
	else if (c.second < c.first && c.second < c.third && c.first > c.third)
		ft_exit(NULL, a, b, ft_rotate(a, FALSE, TRUE));
	else if (c.third > c.first && c.third < c.second)
	{
		ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE));
		ft_exit(NULL, a, b, ft_rotate(a, FALSE, TRUE));
	}
	else
		ft_check_equals(a, b, &c);
}

/*Pushesh the smallest content node to b*/
static void	ft_push_smallest_to_b(t_stackinfo *a, t_stackinfo *b, t_index *i,
		size_t middle)
{
	t_list	*current;

	current = a->stack;
	while (current)
	{
		if (ft_intcmp(current->content, &i->smallest_content) < 0)
		{
			i->smallest_content = *(int *)current->content;
			i->smallest_index = i->i;
		}
		current = current->next;
		i->i++;
	}
	while (ft_intcmp(a->stack->content, &i->smallest_content) != 0
		&& i->is_sorted == FALSE)
	{
		if (i->smallest_index == 1)
			ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE));
		else if (i->smallest_index > (ssize_t)middle)
		{
			ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE));
			i->smallest_index++;
		}
		else
		{
			ft_exit(NULL, a, b, ft_rotate(a, FALSE, TRUE));
			i->smallest_index--;
		}
		if (i->smallest_index > (ssize_t)a->curr_stack_len)
			i->smallest_index = 0;
		if (i->smallest_index < 0)
			i->smallest_index = (ssize_t)a->curr_stack_len - 1;
		if (ft_is_sorted_or_unique(a->stack, FALSE))
			i->is_sorted = TRUE;
	}
	if (i->is_sorted == FALSE)
		ft_exit(NULL, a, b, ft_push(a, b, FALSE));
}

/* Sort stack of 5 */
void	ft_sort_stack(t_stackinfo *a, t_stackinfo *b)
{
	size_t	middle_ind;
	t_index	i;

	i.is_sorted = FALSE;
	while (i.is_sorted == FALSE && a->curr_stack_len > 3)
	{
		ft_init_all(NULL, NULL, &i, NULL);
		middle_ind = a->curr_stack_len / 2 + 1;
		ft_push_smallest_to_b(a, b, &i, middle_ind);
	}
	ft_sort_3(a, b);
	while (b->stack)
		ft_exit(NULL, a, b, ft_push(a, b, TRUE));
	ft_printstack(a, b);
}
