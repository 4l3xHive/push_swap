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

static void	ft_start_sorting(t_stackinfo *a, t_stackinfo *b)
{
	if (ft_is_sorted_or_unique(a->stack, TRUE) == FALSE)
		ft_exit(a, NULL, 0);
	if (a->curr_stack_len == 2)
		ft_exit(a, b, ft_swap(a, TRUE, FALSE));
	else if (a->curr_stack_len == 3)
		ft_sort_3(a, b);
	else if (a->curr_stack_len < 50)
		ft_insertion_sort(a, b);
	else
		ft_chunk_sort(a, b, 18);
}

static void	ft_init_a(t_stackinfo *a, char **av)
{
	t_index	i;
	char	**arg_nums;

	arg_nums = NULL;
	if (av[1] && !av[2] && ft_strlen(av[1]) == 0)
		ft_exit(a, NULL, 0);
	ft_init_all(NULL, NULL, &i, NULL);
	ft_check_and_convert_args(av, a, &i, arg_nums);
	ft_init_stack_a(a, &i);
}

int	main(int ac, char **av)
{
	t_stackinfo	a;
	t_stackinfo	b;

	ft_init_all(&a, &b, NULL, NULL);
	if (ac >= 2)
	{
		ft_init_a(&a, av);
		ft_start_sorting(&a, &b);
		ft_freeall(NULL, 0, &a, &b);
	}
	return (0);
}
