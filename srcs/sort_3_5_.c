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
		ft_exit(NULL , a, NULL, ft_swap(first, TRUE, FALSE) + pf_check);
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



void	rotate_stack_a_radix(long *stack_a, int *numbers_in_stack_a)
{
	rotate_stack_a(stack_a, numbers_in_stack_a);
	rotate_stack_a(stack_a, numbers_in_stack_a);
}

void	reverse_rotate_stack_a_radix(long *stack_a, int *numbers_in_stack_a)
{
	reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
	reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
}

void	first_stack(t_stackinfo *a, t_stackinfo *b)
{
	t_list *a_s;
	t_list *b_s;

	a_s = a->stack;
	b_s = b->stack;
	if (ft_intcmp(a_s->content, b_s->content))
		ft_exit(NULL, ft_push(a, b, TRUE);
	else if (ft_intcmp(b_s->content, a_s->content) && ft_intcmp(b_s->content, a_s->next->content))
	{
		ft_rotate(a_s, FALSE, TRUE);
		ft_push(a, b, TRUE);
		ft_rotate(a_s, TRUE, TRUE);
	}
	else if ((stack_b[0] > stack_a[1]) && (stack_b[0] < stack_a[2]))
	{
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
	}
	else if (stack_b[0] > stack_a[2])
	{
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		rotate_stack_a(stack_a, numbers_in_stack_a);
	}
}

void	second_stack(long *stack_a, long *stack_b, int *numbers_in_stack_a,
		int *numbers_in_stack_b)
{
	if (stack_b[0] < stack_a[0])
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
	else if ((stack_b[0] > stack_a[0]) && (stack_b[0] < stack_a[1]))
	{
		rotate_stack_a(stack_a, numbers_in_stack_a);
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
	}
	else if ((stack_b[0] > stack_a[1]) && (stack_b[0] < stack_a[2]))
	{
		rotate_stack_a(stack_a, numbers_in_stack_a);
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		swap_stack_a(stack_a, numbers_in_stack_a);
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
	}
	else if ((stack_b[0] > stack_a[2]) && (stack_b[0] < stack_a[3]))
	{
		reverse_rotate_stack_a(stack_a, numbers_in_stack_a);
		push_stack_a(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
		rotate_stack_a_radix(stack_a, numbers_in_stack_a);
	}
	else if (stack_b[0] > stack_a[3])
		parameters(stack_a, stack_b, numbers_in_stack_a, numbers_in_stack_b);
}

void	ft_sort_5(t_stackinfo *a, t_stackinfo *b)
{
	ft_push(a, b, FALSE);
	ft_push(a, b, FALSE);
	ft_sort_3(a);
	ft_printstack(a->stack, b->stack);

	while (b->stack_len != 0)
	{
		if (a->stack_len == 3)
			first_stack(a, b);
		else if (a->stack_len == 4)
			second_stack(a, b);
	}

}