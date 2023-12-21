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
		ft_exit(NULL, a, NULL, ft_swap(a, TRUE, FALSE) + pf_check);
	if (ft_intcmp(first->content, second->content) && ft_intcmp(second->content,
			third->content) && ft_intcmp(first->content, third->content))
	{
		ft_exit(NULL, a, NULL, ft_swap(a, TRUE, FALSE) + pf_check);
		ft_exit(NULL, a, NULL, ft_rotate(a, TRUE, TRUE) + pf_check);
	}
	if (ft_intcmp(first->content, second->content) && ft_intcmp(third->content,
			second->content) && ft_intcmp(first->content, third->content))
		ft_rotate(a, FALSE, TRUE);
	if (ft_intcmp(first->content, second->content) && ft_intcmp(second->content,
			third->content) && ft_intcmp(first->content, third->content))
	{
		ft_exit(NULL, a, NULL, ft_swap(a, TRUE, FALSE) + pf_check);
		ft_exit(NULL, a, NULL, ft_rotate(a, FALSE, TRUE) + pf_check);
	}
	if (ft_intcmp(first->content, second->content) && ft_intcmp(second->content,
			third->content) && ft_intcmp(first->content, third->content))
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

void ft_push_smallest_to_b(t_stackinfo *a, t_stackinfo *b)
{
    t_list 	*current;
	t_index i;

	ft_init_all(NULL, NULL, &i);
    current = a->stack;
    while (current)
	{
        if (ft_intcmp(&i.smallest_content, current->content))
		{
            i.smallest_content = *(int *)current->content;
            i.smallest_index = i.current_index;
        }
        current = current->next;
        i.current_index++;
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

/* Push 2 from a to b && sort a & swap b && push back!*/
void	ft_sort_5(t_stackinfo *a, t_stackinfo *b)
{
	ft_push_smallest_to_b(a, b);
	ft_push_smallest_to_b(a, b);
	ft_sort_3(a);
	if (ft_intcmp(b->stack->next->content, b->stack->content))
		ft_exit(NULL, a, b, ft_swap(b, FALSE, FALSE) + pf_check);
	ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
	ft_exit(NULL, a, b, ft_push(a, b, TRUE) + pf_check);
	ft_printstack(a->stack, b->stack);
}
