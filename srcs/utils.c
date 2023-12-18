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
	int	res;

	res = *(int *)a - *(int *)b;
	if (res > 0)
		return (1);
	return (0);
}

int	ft_rotate_val(int reverse, int rotate_a)
{
	int	val;

	val = 0;
	if (!reverse && rotate_a)
		val = ra;
	else if (reverse && rotate_a)
		val = rra;
	else if (!reverse && !rotate_a)
		val = rb;
	else if (reverse && !rotate_a)
		val = rrb;
	return (val);
}

int	ft_print_action(int val)
{
	char	*action;

	if (val & sa)
		action = "sa\n";
	else if (val & sb)
		action = "sb\n";
	else if (val & ss)
		action = "ss\n";
	else if (val & pa)
		action = "pa\n";
	else if (val & pb)
		action = "pb\n";
	else if (val & ra)
		action = "ra\n";
	else if (val & rb)
		action = "rb\n";
	else if (val & rr)
		action = "rr\n";
	else if (val & rra)
		action = "rra\n";
	else if (val & rrb)
		action = "rrb\n";
	else if (val & rrr)
		action = "rrr\n";
	return (ft_printf("%s", action));
}

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
	ft_printf("|a|    |b|");
}