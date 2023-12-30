/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:06:07 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/28 03:06:08 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_insert_int_to_top(t_stackinfo *a, t_stackinfo *b, int to_insert,
		int insert_a)
{
	t_list	*current;
	t_index	i;

	if (insert_a == TRUE)
	{
		current = a->stack;
		i.middle_index = a->curr_stack_len / 2;
	}
	else
	{
		current = b->stack;
		i.middle_index = b->curr_stack_len / 2;
	}
	ft_init_all(NULL, NULL, &i, NULL);
	while (current)
	{
		if (ft_intcmp(current->content, &to_insert) == 0)
		{
			i.found_content = *(int *)current->content;
			i.found_index = i.i;
		}
		current = current->next;
		i.i++;
	}
	ft_exec_int_to_top(a, b, &i, insert_a);
}

/**
 * @brief Function used to complete the algorithm.
 * Inserts to top the two numbers in parameters and pushing them to a.
 *
 * @param stack_a		pointer to the stack a
 * @param stack_b		pointer to the stack b
 * @param first			the first number to push
 * @param second		the second number to push
 */
static void	ft_insert_and_push(t_stackinfo *a, t_stackinfo *b, int first,
		int second)
{
	ft_insert_int_to_top(a, b, first, FALSE);
	ft_exit(a, b, ft_push(a, b, TRUE));
	ft_insert_int_to_top(a, b, second, FALSE);
	ft_exit(a, b, ft_push(a, b, TRUE));
}

void	ft_find_max_int(t_stackinfo *s, t_index *max_i)
{
	int		max;
	t_list	*current;
	int		current_value;

	if (!s || !s->stack)
		return (0);
	max = *(int *)s->stack->content;
	current = s->stack->next;
	while (current)
	{
		current_value = *(int *)current->content;
		if (current_value > max)
		{
			max = current_value;
			max_i->found_index = max_i->i;
		}
		max_i->i++;
		current = current->next;
	}
	max_i->found_content = max;
}

void	ft_find_next_max_int(t_stackinfo *s, int current_max, t_index *max_i2)
{
	int		next_max;
	t_list	*current;
	int		current_value;

	if (!s || !s->stack)
		return (0);
	next_max = INT_MIN;
	current = s->stack;
	while (current)
	{
		current_value = *(int *)current->content;
		if (current_value > next_max && current_value < current_max)
		{
			next_max = current_value;
			max_i2->found_index = max_i2->i;
		}
		current = current->next;
		max_i2->i++;
	}
	max_i2->found_content = next_max;
}

/**
 * @brief Function used to push everything from the stack b, to
 * the stack a.
 * It'll get the two biggest numbers and will push the one that
 * is the closest to the top of stack b first then the second one.
 *
 * @param stack_a 		pointer to the stack a
 * @param stack_b 		pointer to the stack b
 */
static void	ft_push_b_to_a(t_stackinfo *a, t_stackinfo *b)
{
	t_index	max_i;
	t_index	max_i2;

	ft_init_all(NULL, NULL, &max_i, NULL);
	ft_init_all(NULL, NULL, &max_i2, NULL);
	while (b->curr_stack_len)
	{
		ft_find_max_int(b, &max_i);
		ft_find_next_max_int(b, max_i.found_content, &max_i2);
		if (max_i.found_index > b->curr_stack_len / 2)
			max_i.found_index = b->curr_stack_len - max_i.found_index;
		if (max_i2.found_index > b->curr_stack_len / 2)
			max_i2.found_index = b->curr_stack_len - max_i2.found_index;
		if (max_i.found_index < max_i2.found_index)
			ft_insert_and_push(a, b, max_i.found_content, max_i2.found_content);
		else
			ft_insert_and_push(a, b, max_i2.found_content, max_i.found_content);
		if (ft_intcmp(a->stack->content, a->stack->next->content))
			ft_exit(a, b, ft_swap(a, TRUE, FALSE));
	}
}

/**
 * @brief Quick sort algorithm based function, called chunk sort here.
 * It'll creates small stacks of chunk_size integers.
 *
 * @param stack_a 		pointer to the stack a
 * @param stack_b 		pointer to the stack b
 * @param chunk_size 	the size of a chunk
 */
void	ft_chunk_sort(t_stackinfo *a, t_stackinfo *b, int chunk_size)
{
	int		index;
	int		min_int;
	int		times;
	t_index	i;

	ft_init_all(NULL, NULL, &i, NULL);
	while (a->curr_stack_len)
	{
		i.middle_index = a->curr_stack_len / 2;
		times = 0;
		min_int = ft_find_min_int(a);
		while (times++ < chunk_size)
		{
			min_int = ft_find_next_min_int(a, min_int);
			if (times == chunk_size / 2)
				i.middle_index = min_int;
		}
		times = 0;
		while (times++ < chunk_size)
		{
			ft_min_to_top(a, b, &i, TRUE);
			ft_exit(a, b, ft_push(a, b, FALSE));
			if (*(int *)b->stack->content < *(int *)a->stack->content)
				ft_exit(a, b, ft_rotate(b, FALSE, FALSE));
		}
	}
	ft_push_b_to_a(a, b);
}
