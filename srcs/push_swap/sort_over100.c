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

static void ft_insert_int_to_top(t_stackinfo *a, t_stackinfo *b, int to_insert, int insert_a)
{
	t_list	*current;
	t_index	i;

	if (insert_a == TRUE)
	{
		current = a->stack;
		i.middle_index = a->curr_stack_len /2;
	}
	else
	{
		current = b->stack;
		i.middle_index = b->curr_stack_len /2;
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
	ft_insert_int_to_top(b, second, FALSE);
	ft_exit(a, b, ft_push(a, b, TRUE));
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
	int	first;
	int	second;
	int	first_index;
	int	second_index;

	while (b->curr_stack_len)
	{
		first = ft_find_max_int(b);
		second = ft_find_next_max_int(b, first);
		first_index = ft_get_index_of_int(b, first);
		second_index = ft_get_index_of_int(b, second);
		if (first_index > stack_b->size / 2)
			first_index = stack_b->size - first_index;
		if (second_index > stack_b->size / 2)
			second_index = stack_b->size - second_index;
		if (first_index < second_index)
			ft_insert_and_push(stack_a, stack_b, first, second);
		else
			ft_insert_and_push(stack_a, stack_b, second, first);
		if (stack_a->stack[0] > stack_a->stack[1])
			ft_do_swap(stack_a, 'a');
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
	int	index;
	int	min_int;
	int	times;
	t_index i;

	while (a->curr_stack_len)
	{
		times = 0;
		min_int = ft_find_min_int(a);
		while (times++ < chunk_size)
		{
			min_int = ft_find_next_min_int(a, min_int);
			if (times == chunk_size / 2)
				stack_a->middle_index = min_int;
		}
		times = 0;
		while (times++ < chunk_size)
		{
			ft_min_to_top(a, b, &i, TRUE);
			ft_exit(a, b, ft_push(a, b, FALSE));
			if (*(int *)b->stack->content < a->stack)
				ft_do_rotate(b, 'b');
		}
	}
	ft_push_b_to_a(a, b);
}
