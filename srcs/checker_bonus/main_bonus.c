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

#include "checker_bonus.h"

static void	ft_handle_action(char *command, t_stackinfo *a, t_stackinfo *b)
{
	if (ft_strcmp(command, "sa\n") == 0)
		ft_swap(a);
	else if (ft_strcmp(command, "sb\n") == 0)
		ft_swap(b);
	else if (ft_strcmp(command, "ss\n") == 0)
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (ft_strcmp(command, "pa\n") == 0)
		ft_push(a, b, TRUE);
	else if (ft_strcmp(command, "pb\n") == 0)
		ft_push(a, b, FALSE);
	else if (ft_strcmp(command, "ra\n") == 0)
		ft_rotate(a, FALSE);
	else if (ft_strcmp(command, "rb\n") == 0)
		ft_rotate(b, FALSE);
	else if (ft_strcmp(command, "rr\n") == 0)
	{
		ft_rotate(a, FALSE);
		ft_rotate(b, FALSE);
	}
	else if (ft_strcmp(command, "rra\n") == 0)
		ft_rotate(a, TRUE);
	else if (ft_strcmp(command, "rrb\n") == 0)
		ft_rotate(b, TRUE);
	else if (ft_strcmp(command, "rrr\n") == 0)
	{
		ft_rotate(a, TRUE);
		ft_rotate(b, TRUE);
	}
}

static void	ft_start_listening(t_stackinfo *a, t_stackinfo *b)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		ft_handle_action(command, a, b);
	}
	if (!ft_is_sorted_or_unique(a->stack, FALSE) || b->curr_stack_len > 0)
		ft_exit(a, b, ft_printf("\x1B[31mKO\n\x1B[0m"));
	else
		ft_exit(a, b, ft_printf("\x1B[32mOK\n\x1B[0m"));
}

static void	ft_init_a(t_stackinfo *a, char **av)
{
	t_index	i;
	char	**arg_nums;

	arg_nums = NULL;
	if (av[1] && !av[2] && ft_strlen(av[1]) == 0)
		ft_exit(a, NULL, 0);
	ft_init_all(NULL, NULL, &i);
	ft_check_and_convert_args(av, a, &i, arg_nums);
	ft_init_stack_a(a, &i);
}

int	main(int ac, char **av)
{
	t_stackinfo	a;
	t_stackinfo	b;

	ft_init_all(&a, &b, NULL);
	if (ac >= 2)
	{
		ft_init_a(&a, av);
		if (ft_is_sorted_or_unique(a.stack, TRUE) == FALSE)
			ft_exit(&a, &b, 0);
		ft_start_listening(&a, &b);
		ft_freeall(NULL, 0, &a, &b);
	}
	return (0);
}
