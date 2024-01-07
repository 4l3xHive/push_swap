void	ft_printstack(t_stackinfo *a, t_stackinfo *b)
{
	t_list	*curr1;
	t_list	*curr2;

	curr2 = b->stack;
	curr1 = a->stack;
	while (curr1 || curr2)
	{
		if (curr1)
		{
			ft_exit(a, b, ft_printf("%d", *(int *)curr1->content));
			curr1 = curr1->next;
		}
		if (curr2)
		{
			ft_exit(a, b, ft_printf("%d", *(int *)curr1->content));
			curr2 = curr2->next;
		}
		ft_exit(a, b, write(1, "\n", 1));
	}
	ft_exit(a, b, ft_printf("|a|    |b|\n"));
}
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
	if (ft_intcmp(a_s->content, b_s->content))
		ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE) + pf_check);
	else if ((ft_intcmp(b_s->content, a_s->content))
		&& (ft_intcmp(a_s->next->content, b_s->content)))
	{
		ft_exit(NULL, a, b, ft_rotate(a_s, FALSE, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a_s, TRUE, TRUE) + pf_check);
	}
	else if ((ft_intcmp(b_s->content, a_s->next->content))
		&& (ft_intcmp(a_s->next->next->content, b_s->content)))
	{
		ft_exit(NULL, a, b, ft_rotate(a_s, FALSE, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_swap(a_s, TRUE, FALSE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a_s, TRUE, TRUE) + pf_check);
	}
	else if (ft_intcmp(a_s->next->next->content, b_s->content)
		&& (ft_intcmp(b_s->content, a_s->next->next->next->content)))
	{
		ft_exit(NULL, a, b, ft_rotate(a_s, TRUE, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE) + pf_check);
		ft_rotate_stack_radix(a, b, TRUE, FALSE);
	}
	else if (ft_intcmp(b_s->content, a_s->next->next->next->content))
	{
		ft_exit(NULL, a, b, ft_push(a, b, &a_s, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a_s, FALSE, TRUE) + pf_check);
	}
}
void	ft_sort_5(t_stackinfo *a, t_stackinfo *b)
{
	ft_push(a, b, NULL, FALSE);
	ft_push(a, b, NULL, FALSE);
	ft_sort_3(a);
	// ft_printstack(a->stack, b->stack);
	while (b->curr_stack_len != 0)
	{
		if (a->curr_stack_len == 3)
			first_stack(a, b);
		else if (a->curr_stack_len == 4)
			second_stack(a, b);
	}
}

int	ft_rotate(t_list *stack, int reverse, int rotate_a)
{
	t_list	*tail;
	t_list	*head;
	void	*tmp_c;

	tail = stack;
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
	return (ft_print_action(ft_rotate_val(reverse, rotate_a)));
}

void	first_stack(t_stackinfo *a, t_stackinfo *b)
{
	if (ft_intcmp(a->stack->content, b->stack->content))
		ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
	else if (ft_intcmp(b->stack->content, a->stack->content)
		&& ft_intcmp(b->stack->content, a->stack->next->content))
	{
		ft_exit(NULL, a, b, ft_rotate(a, FALSE, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
	}
	else if ((ft_intcmp(b->stack->content, a->stack->next->content))
		&& ft_intcmp(b->stack->content, a->stack->next->next->content))
	{
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
		ft_rotate_stack_radix(a, b, TRUE, TRUE);
	}
	else if (ft_intcmp(b->stack->content, a->stack->next->next->content))
	{
		ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a, FALSE, TRUE) + pf_check);
	}
}

void	second_stack(t_stackinfo *a, t_stackinfo *b)
{
	if (ft_intcmp(a->stack->content, b->stack->content))
		ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
	else if ((ft_intcmp(b->stack->content, a->stack->content))
		&& (ft_intcmp(a->stack->next->content, b->stack->content)))
	{
		ft_exit(NULL, a, b, ft_rotate(a, FALSE, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
	}
	else if ((ft_intcmp(b->stack->content, a->stack->next->content))
		&& (ft_intcmp(a->stack->next->next->content, b->stack->content)))
	{
		ft_exit(NULL, a, b, ft_rotate(a, FALSE, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
	}
	else if (ft_intcmp(a->stack->next->next->content, b->stack->content)
		&& (ft_intcmp(b->stack->content, a->stack->next->next->next->content)))
	{
		ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
		ft_rotate_stack_radix(a, b, TRUE, FALSE);
	}
	else if (ft_intcmp(b->stack->content, a->stack->next->next->next->content))
	{
		ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
		ft_exit(NULL, a, b, ft_rotate(a, FALSE, TRUE) + pf_check);
	}
}

void	ft_push_smallest_to_b(t_stackinfo *a, t_stackinfo *b)
{
	t_list	*current;
	t_index	i;

	ft_init_helpers(NULL, NULL, &i);
	current = a->stack;
	while (current)
	{
		if (ft_intcmp(&i.smallest_content, current->content))
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
		else if (i.smallest_index == 2)
		{
			ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
			ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE) + pf_check);
		}
		else
			ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
	}
	ft_exit(NULL, a, b, ft_push(a, b, FALSE) + pf_check);
}

/*
void	ft_push_largest_to_b(t_stackinfo *a, t_stackinfo *b)
{
	t_list	*current;
	t_index	i;

	ft_init_all(NULL, NULL, &i);
	current = a->stack;
	while (current)
	{
		if (ft_intcmp(current->content, &i.largest_content) > 0)
		{
			i.largest_content = *(int *)current->content;
			i.largest_index = i.i;
		}
		current = current->next;
		i.i++;
	}
	while(ft_intcmp(a->stack->content, &i.largest_content) != 0)
	{
		if (i.largest_index == 1)
			ft_exit(NULL, a, b, ft_swap(a, TRUE, FALSE) + pf_check);
		else
			ft_exit(NULL, a, b, ft_rotate(a, TRUE, TRUE) + pf_check);
	}
	ft_exit(NULL, a, b, ft_push(a, b, FALSE) + pf_check);
}
*/
void	sort_a_section_of_the_stack(long *array, int *stack_size)
{
	long	i;
	long	j;
	long	temporary;

	i = 0;
	j = 0;
	while (i < stack_size[0])
	{
		j = i + 1;
		while (j < stack_size[0])
		{
			if (array[i] > array[j])
			{
				temporary = array[i];
				array[i] = array[j];
				array[j] = temporary;
			}
			j++;
		}
		i++;
	}
}

void	swap_stack_a_first_time(long *copy, long *copy_swap_stack_a,
		long *stack_a, int *numbers_in_stack_a)
{
	int	i;

	i = 0;
	while (i < numbers_in_stack_a[0])
	{
		copy[i] = stack_a[i];
		copy_swap_stack_a[i] = stack_a[i];
		i++;
	}
}

void	swap_stack_a_second_time(long *copy, long *copy_swap_stack_a,
		long *stack_a, int *numbers_in_stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < numbers_in_stack_a[1])
	{
		j = 0;
		while (j < numbers_in_stack_a[0])
		{
			if (copy_swap_stack_a[i] == copy[j])
				stack_a[i] = j;
			j++;
		}
		++i;
	}
}

void	swap_stack_a_third_time(long *stack_a, long *stack_b,
		int *numbers_in_stack_a, int *numbers_in_stack_b)
{
	int	maximum_number;
	int	maximum_bits;
	int	loop_through[2];

	maximum_number = numbers_in_stack_a[1] - 1;
	maximum_bits = 0;
	loop_through[0] = 0;
	loop_through[1] = 0;
	while ((maximum_number >> maximum_bits) != 0)
		++maximum_bits;
	while (loop_through[0] < maximum_bits)
	{
		loop_through[1] = 0;
		while (loop_through[1] < numbers_in_stack_a[0])
		{
			if (((stack_a[0] >> loop_through[0]) & 1) == 1)
				rotate_stack_a(stack_a, numbers_in_stack_a);
			else
				push_stack_b(stack_a, stack_b, numbers_in_stack_a,
					numbers_in_stack_b);
			++loop_through[1];
		}
		while (*numbers_in_stack_b != 0)
			push_stack_a(stack_a, stack_b, numbers_in_stack_a,
				numbers_in_stack_b);
		++loop_through[0];
	}
}

void	sort_beyond_3_and_5_numbers(long *stack_a, long *stack_b,
		int *numbers_in_stack_a, int *numbers_in_stack_b)
{
	long	*copy;
	long	*copy_swap_stack_a;

	copy = (long *)malloc(numbers_in_stack_a[0] * sizeof(long));
	copy_swap_stack_a = (long *)malloc(numbers_in_stack_a[0] * sizeof(long));
	swap_stack_a_first_time(copy, copy_swap_stack_a, stack_a,
		numbers_in_stack_a);
	sort_a_section_of_the_stack(copy, numbers_in_stack_a);
	swap_stack_a_second_time(copy, copy_swap_stack_a, stack_a,
		numbers_in_stack_a);
	free(copy);
	free(copy_swap_stack_a);
	swap_stack_a_third_time(stack_a, stack_b, numbers_in_stack_a,
		numbers_in_stack_b);
}

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
	ft_init_helpers(NULL, NULL, &i, NULL);
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
void	ft_find_extreme_int(t_stackinfo *s, t_index *i, int find_max)
{
	int		extreme;
	t_list	*current;
	int		current_value;

	if (find_max)
		extreme = *(int *)s->stack->content;
	else
		extreme = INT_MAX;
	current = s->stack->next;
	while (current)
	{
		current_value = *(int *)current->content;
		if ((find_max && current_value > extreme) || (!find_max
				&& current_value < extreme))
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
int	ft_find_next_extreme_int(t_stackinfo *s, int current_extreme, t_index *i,
		int find_max)
{
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
	while (current)
	{
		current_value = *(int *)current->content;
		if ((find_max && current_value > next_extreme
				&& current_value < current_extreme) || (!find_max
				&& current_value < next_extreme
				&& current_value > current_extreme))
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

	ft_init_helpers(NULL, NULL, &max_i, NULL);
	ft_init_helpers(NULL, NULL, &max_i2, NULL);
	while (b->curr_stack_len)
	{
		ft_find_extreme_int(b, &max_i, TRUE);
		ft_find_next_extreme_int(b, max_i.found_content, &max_i2, TRUE);
		if (max_i.found_index > (ssize_t)b->curr_stack_len / 2)
			max_i.found_index = (ssize_t)b->curr_stack_len - max_i.found_index;
		if (max_i2.found_index > (ssize_t)b->curr_stack_len / 2)
			max_i2.found_index = (ssize_t)b->curr_stack_len
				- max_i2.found_index;
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
	t_index	min_i;

	ft_init_helpers(NULL, NULL, &i, NULL);
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

#include "push_swap.h"

void	radix_my_b(t_stackinfo *a, t_stackinfo *b, int msb)
{
	size_t	i;

	// int	size_list_b;
	i = 0;
	b->curr_stack_len = ft_lstsize(b->stack);
	while (i++ < b->curr_stack_len && !ft_is_sorted_or_unique(a->stack, FALSE))
	{
		if (*(int *)b->stack->content & (1u << msb))
			ft_exit(a, b, ft_push(a, b, TRUE));
		// pa(list_a, list_b);
		else
			ft_exit(a, b, ft_rotate(b, FALSE, FALSE));
		// rb(list_b);
	}
}

void	radix_my_a(t_stackinfo *a, t_stackinfo *b, int msb)
{
	size_t	i;

	// int	size_list_a;
	i = 0;
	a->curr_stack_len = ft_lstsize(a->stack);
	while (i++ < a->curr_stack_len && !ft_is_sorted_or_unique(a->stack, FALSE))
	{
		if (*(int *)a->stack->content & (1u << msb))
			ft_exit(a, b, ft_rotate(a, FALSE, TRUE));
		// ra(list_a);
		else
			ft_exit(a, b, ft_push(a, b, FALSE));
		// pb(list_a, list_b);
	}
}

int	get_msb(t_list *list_a)
{
	int	msb;
	int	biggest;

	biggest = INT_MIN;
	while (list_a)
	{
		if (biggest < *(int *)list_a->content)
			biggest = *(int *)list_a->content;
		list_a = list_a->next;
	}
	msb = 0;
	while (biggest)
	{
		biggest = biggest >> 1;
		msb++;
	}
	return (msb);
}

void	ft_sort_big(t_stackinfo *a, t_stackinfo *b)
{
	int pos_msb;
	int cont;

	pos_msb = get_msb(a->stack);
	cont = pos_msb;
	while (cont)
	{
		radix_my_a(a, b, pos_msb - cont);
		cont--;
		radix_my_b(a, b, pos_msb - cont);
	}
	while (b->stack)
		ft_exit(a, b, ft_push(a, b, TRUE));
	ft_printstack(a, b);
}