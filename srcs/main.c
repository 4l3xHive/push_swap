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

void	ft_exit_error(const char *err_msg, int exit_val)
{
	if (exit_val == EXIT_FAILURE)
		ft_putstr_fd((char *)err_msg, STDERR_FILENO);
	else if (exit_val == EXIT_SUCCESS)
		ft_putstr_fd((char *)err_msg, STDOUT_FILENO);
	exit(exit_val);
}

int	ft_check_args(char **av, t_stackinfo *info)
{
	size_t	i;
	char	**split_nums;

	i = 0;
	split_nums = ft_split(av[1], ' ');
	if (!split_nums)
		return (-1);
	while (split_nums[i])
		i++;
	info->stack_len = i;
	info->nums = (int *)malloc(sizeof(int) * i);
	if (info->nums == NULL)
		return (ft_freeall(split_nums, i, NULL, NULL));
	i = 0;
	while (split_nums[i])
	{
		info->nums[i] = ft_atoi(split_nums[i]);
		i++;
	}
	ft_freeall(split_nums, i, NULL, NULL);
	return (0);
}
int	ft_init_list_a(t_stackinfo *a)
{
	size_t	i;
	t_list	*temp;

	i = 0;
	temp = NULL;
	a->stack = NULL;
	if (a->nums)
	{
		while (i < a->stack_len)
		{
			temp = ft_lstnew(&a->nums[i++]);
			if (!temp)
				return (ft_freeall(NULL, 0, a, NULL));
			ft_lstadd_back(&a->stack, temp);
		}
	}
	return (0);
}

void	ft_init_stack_a(char **av, t_stackinfo *a)
{
	if (ft_check_args(av, a) == -1)
		ft_exit_error("ERROR: Checking args!\n", EXIT_FAILURE);
	if (ft_init_list_a(a) == -1)
		ft_exit_error("ERROR: Failure initing a stacklist!\n", EXIT_FAILURE);
}

int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	main(int ac, char **av)
{
	t_stackinfo	a_stack;
	t_stackinfo	b_stack;

	b_stack.nums = NULL;
	b_stack.stack = NULL;
	if (ac == 2)
	{
		ft_init_stack_a(av, &a_stack);
		// DO THE QSORT YOUR OWN
		qsort(a_stack.nums, a_stack.stack_len, sizeof(int), compare);
		for (size_t i = 0; i < a_stack.stack_len; i++)
		{
			printf("%d  ", a_stack.nums[i]);
		}
		// ft_firstcheck(&a_stack);
		// ft_create_indices(a_stack);
		// b_stack.stack = ft_lstnew(&tst);
		// ft_lstadd_back(&b_stack.stack, ft_lstnew(&tst2));
		// ft_push_stack(&a_stack.stack, &b_stack.stack, TRUE);
		// ft_printstack(a_stack.stack, b_stack.stack);
		printf("nums %d\n\n", *(int *)a_stack.stack->content);
		// ft_printstack(a_stack.stack, b_stack.stack);
		ft_freeall(NULL, 0, &a_stack, &b_stack);
	}
	// list = ft_convert_args(av);
}

/*
int	ft_firstcheck(t_stackinfo *info)
{
	t_list	*stack;
	t_list	*last;

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