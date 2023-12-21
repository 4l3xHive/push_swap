/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:47:36 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/18 01:47:37 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}
// Checks that if the stack is sorted
int	ft_is_stack_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}
// prints bnoth sta
void	ft_printstack(t_list *a, t_list *b)
{
	t_list *curr1;
	t_list *curr2;

	curr2 = b;
	curr1 = a;
	while (curr1 || curr2)
	{
		if (curr1)
		{
			ft_printf("%d", *(int *)curr1->content);
			curr1 = curr1->next;
		}
		if (curr2)
		{
			ft_printf("      %d", *(int *)curr2->content);
			curr2 = curr2->next;
		}
		write(1, "\n", 1);
	}
	ft_printf("|a|    |b|\n");
}