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

static void	ft_sort3_extrachecks(t_stackinfo *a, t_stackinfo *b, t_sort3 *c)
{
	if (c->third > c->first && c->third < c->second)
	{
		ft_exit(a, b, ft_swap(a, TRUE, FALSE));
		ft_exit(a, b, ft_rotate(a, FALSE, TRUE));
	}
	else if (c->second > c->first && c->second > c->third
		&& c->first < c->third)
	{
		ft_exit(a, b, ft_rotate(a, TRUE, TRUE));
		ft_exit(a, b, ft_swap(a, TRUE, FALSE));
	}
	else if (c->first == c->second && c->second < c->third)
		ft_exit(a, b, ft_rotate(a, TRUE, TRUE));
	else if (c->first == c->second && c->second > c->third)
		ft_exit(a, b, ft_rotate(a, TRUE, TRUE));
	else if (c->second == c->third && c->first < c->second)
		ft_exit(a, b, ft_rotate(a, TRUE, TRUE));
	else if (c->second == c->third && c->first > c->second)
		ft_exit(a, b, ft_rotate(a, TRUE, TRUE));
}

/* Sorts stack of 3 if not sorted*/
void	ft_sort_3(t_stackinfo *a, t_stackinfo *b)
{
	t_sort3	c;

	ft_init_all(a, NULL, NULL, &c);
	if (c.first > c.second && c.first < c.third && c.second < c.third)
		ft_exit(a, b, ft_swap(a, TRUE, FALSE));
	else if (c.first > c.second && c.second > c.third)
	{
		ft_exit(a, b, ft_swap(a, TRUE, FALSE));
		ft_exit(a, b, ft_rotate(a, TRUE, TRUE));
	}
	else if (c.first > c.third && c.second > c.third && c.second > c.first)
		ft_exit(a, b, ft_rotate(a, TRUE, TRUE));
	else if (c.first > c.second && c.first < c.third)
		ft_exit(a, b, ft_swap(a, TRUE, FALSE));
	else if (c.second < c.first && c.second < c.third && c.first > c.third)
		ft_exit(a, b, ft_rotate(a, FALSE, TRUE));
	else
		ft_sort3_extrachecks(a, b, &c);
}

/* Finds the smallest for push_smallest to b*/
static void	ft_find_smallest(t_stackinfo *a, t_stackinfo *b, t_index *i)
{
	while (ft_intcmp(a->stack->content, &i->smallest_content) != 0
		&& i->is_sorted == FALSE)
	{
		if (i->smallest_index == 1)
			ft_exit(a, b, ft_swap(a, TRUE, FALSE));
		else if (i->smallest_index > (ssize_t)i->middle)
		{
			ft_exit(a, b, ft_rotate(a, TRUE, TRUE));
			i->smallest_index++;
		}
		else
		{
			ft_exit(a, b, ft_rotate(a, FALSE, TRUE));
			i->smallest_index--;
		}
		if (i->smallest_index > (ssize_t)a->curr_stack_len)
			i->smallest_index = 0;
		if (i->smallest_index < 0)
			i->smallest_index = (ssize_t)a->curr_stack_len - 1;
		if (ft_is_sorted_or_unique(a->stack, FALSE))
			i->is_sorted = TRUE;
	}
}

/**
 * @brief Puts the smallest content node to top of the stack
 * 	@param a pointer to a stack info
 * 	@param b pointer to b stack info
 * 	@param i pointer to index struct
 * 	@param is_a is the stack a or b
 */
void	ft_min_to_top(t_stackinfo *a, t_stackinfo *b, t_index *i, int is_a)
{
	t_list	*current;

	if (is_a == TRUE)
		current = a->stack;
	else
		current = b->stack;
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
	ft_find_smallest(a, b, i);
}

/**
 * @brief Sort stack under 100 with insertionsort
 * 	push smallest from a to b until its sorted or len 3
 * 	@param a pointer to a stack info
 * 	@param b pointer to b stack info*					**/
void	ft_insertion_sort(t_stackinfo *a, t_stackinfo *b)
{
	t_index	i;

	i.is_sorted = ft_is_sorted_or_unique(a->stack, FALSE);
	i.smallest_index = -1;
	while (i.is_sorted == FALSE && a->curr_stack_len > 3)
	{
		ft_init_all(NULL, NULL, &i, NULL);
		i.middle = a->curr_stack_len / 2 + 1;
		ft_min_to_top(a, b, &i, TRUE);
		if (i.is_sorted == FALSE)
			ft_exit(a, b, ft_push(a, b, FALSE));
	}
	ft_sort_3(a, b);
	while (b->stack)
		ft_exit(a, b, ft_push(a, b, TRUE));
}
