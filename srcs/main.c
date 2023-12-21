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
	ft_check_args(av, a);
	ft_init_stack_a(a);
	if (ft_is_stack_sorted(a->stack))
		ft_exit("ERROR: already sorted!\n", a, NULL, 0);
}

static void	ft_start_sorting(t_stackinfo *a, t_stackinfo *b)
{
	if (a->stack_len == 2)
		ft_exit(NULL, a, b, ft_swap(a->stack, TRUE, FALSE));
	if (a->stack_len == 3)
		ft_sort_3(a);
	if (a->stack_len == 5)
		ft_sort_5(a, b);
}

int	main(int ac, char **av)
{
	t_stackinfo	a;
	t_stackinfo	b;

	ft_null_init(&a, &b);
	if (ac == 2)
	{
		ft_init_a(av, &a);
		ft_printstack(a.stack, b.stack);
		ft_start_sorting(&a, &b);
		printf("\n\n");
		ft_printstack(a.stack, b.stack);
		ft_freeall(NULL, 0, &a, &b);
	}
	return (0);
}
