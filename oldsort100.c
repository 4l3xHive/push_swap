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

static void	ft_insert_and_push(t_stackinfo *a, t_stackinfo *b, int first,
		int second)
{
	ft_insert_int_to_top(a, b, first, FALSE);
	ft_exit(a, b, ft_push(a, b, TRUE));
	ft_insert_int_to_top(a, b, second, FALSE);
	ft_exit(a, b, ft_push(a, b, TRUE));
}


/**
 * @brief Finds the max or min content from the stack & stores it into t_index.
 *
 * @param s				Pointer to the stack.
 * @param i				Pointer to the struct where we store the index and content found.
 * @param find_max		Determines that are finding max or min.
 */
void ft_find_extreme_int(t_stackinfo *s, t_index *i, int find_max)
{
    int extreme;
    t_list *current;
    int current_value;

    if (find_max)
        extreme = *(int *)s->stack->content;
	else
        extreme = INT_MAX;

    current = s->stack->next;
    while (current)
	{
        current_value = *(int *)current->content;
        if ((find_max && current_value > extreme) ||
            (!find_max && current_value < extreme))
		{
            extreme = current_value;
            i->found_index = i->i;
        }
        i->i++;
        current = current->next;
    }
    i->found_content = extreme;
}

/**
 * @brief Finds the next smallest or next biggest from current_exterme value
 * @param s					Pointer to stack where to find
 * @param current_extreme	Value from what we find the next
 * @param i 				Is structure where we store the index and value that we found.
 * @param find_max 			Determines that do we need to find next from the max or min.
 */
int	ft_find_next_extreme_int(t_stackinfo *s, int current_extreme, t_index *i, int find_max) {
	int		next_extreme;
	t_list	*current;
	int		current_value;

	if (!s || !s->stack)
		return (1);
	if (find_max)
		next_extreme = INT_MIN;
	else
		next_extreme = INT_MAX;
	current = s->stack;
	while (current) {
		current_value = *(int *)current->content;
		if ((find_max && current_value > next_extreme && current_value < current_extreme) ||
		    (!find_max && current_value < next_extreme && current_value > current_extreme))
		{
			next_extreme = current_value;
			i->found_index = i->i;
		}
		i->i++;
		current = current->next;
	}
	i->found_content = next_extreme;
	return (0);
}


/**
 * @brief Function used to push everything from the stack b, to
 * the stack a.
 * It'll get the two biggest numbers and will push the one that
 * is the closest to the top of stack b first then the second one.
 *
 * @param a 		pointer to the stack a
 * @param b 		pointer to the stack b
 */
static void	ft_push_b_to_a(t_stackinfo *a, t_stackinfo *b)
{
	t_index	max_i;
	t_index	max_i2;

	ft_init_all(NULL, NULL, &max_i, NULL);
	ft_init_all(NULL, NULL, &max_i2, NULL);
	while (b->curr_stack_len)
	{
		ft_find_extreme_int(b, &max_i, TRUE);
		ft_find_next_extreme_int(b, max_i.found_content, &max_i2, TRUE);
		if (max_i.found_index > (ssize_t)b->curr_stack_len / 2)
			max_i.found_index = (ssize_t)b->curr_stack_len - max_i.found_index;
		if (max_i2.found_index > (ssize_t)b->curr_stack_len / 2)
			max_i2.found_index = (ssize_t)b->curr_stack_len - max_i2.found_index;
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
 * @param a 		pointer to the stack a
 * @param b 		pointer to the stack b
 * @param chunk_size 	the size of a chunk
 */
void	ft_chunk_sort(t_stackinfo *a, t_stackinfo *b, int chunk_size)
{
	int		times;
	t_index	i;
	t_index min_i;

	ft_init_all(NULL, NULL, &i, NULL);
	while (a->curr_stack_len)
	{
		i.middle_index = a->curr_stack_len / 2;
		times = 0;
		ft_find_extreme_int(a, &min_i, FALSE);
		while (times++ < chunk_size)
		{
			ft_find_next_extreme_int(a, min_i.found_content, &min_i, FALSE);
			if (times == chunk_size / 2)
				i.middle_index = min_i.found_content;
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
