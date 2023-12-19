/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:42:07 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/16 15:31:17 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Init a stack with given arguments */
static void	ft_init_a(char **av, t_stackinfo *a)
{
	if (ft_check_args(av, a) == ERROR)
		ft_exit("ERROR: Checking args!\n", NULL, NULL, 0);
	if (ft_init_stack_a(a) == ERROR)
		ft_exit("ERROR: Init a stack!\n", a, NULL, 0);
	if (ft_is_stack_sorted(a->stack))
		ft_exit("ERROR: already sorted!\n", a, NULL, 0);
}

/*
static void	ft_start_sorting(t_stackinfo *a, t_stackinfo *b)
{
	if (a->stack_len == 2)
		ft_exit(NULL, a, b, ft_swap(a->stack, TRUE, FALSE));
	if (a->stack_len == 3)
		ft_sort_3(a);
	if (a->stack_len == 5)
		ft_sort_5(a, b);
}*/

int	main(int ac, char **av)
{
	t_stackinfo	a;
	t_stackinfo	b;

	ft_null_init(&a, &b);
	if (ac == 2)
	{
		ft_init_a(av, &a);
		ft_push(&a, &b, FALSE);
		ft_push(&a, &b, FALSE);
		printf("len a %lu len b %lu\n\n", a.stack_len, b.stack_len);
		ft_push(&a,&b, TRUE);
		//ft_start_sorting(&a, &b);
		ft_printstack(a.stack, b.stack);
		ft_freeall(NULL, 0, &a, &b);
	}
	return (0);
}

/*
int	ft_firstcheck(t_stackinfo *info)
{
	t_stackinfo	a;
	t_stackinfo	b;
	t_list		*stack;
	t_list		*last;

	stack = info->stack;
	last = ft_lstlast(stack);
	if (info->stack_len >= 2)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			ft_swap_stack(stack);
	}
	return (FALSE);
}
*/