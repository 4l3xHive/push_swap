/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:42:07 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/14 00:08:26 by apyykone         ###   ########.fr       */
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

int	*ft_check_args(char **av, int *len)
{
	int		num;
	size_t	i;
	int		*nums;

	*len = ft_strlen(av[1]);
	i = 0;
	num = ft_atoi(av[1]);
	if (num <= 0)
		return (NULL);
	nums = (int *)malloc(sizeof(int) * *len);
	if (!nums)
		return (NULL);
	while (num)
	{
		nums[i++] = num % 10;
		num /= 10;
	}
	return (nums);
}

t_list	*ft_init_list(int *nums, int arg_len, int *list_len)
{
	int		i;
	t_list	*first;

	i = 0;
	first = NULL;
	if (nums)
	{
		while (i < arg_len)
			ft_lstadd_back(&first, ft_lstnew(&nums[i++]));
		*list_len = ft_lstsize(first);
		if (arg_len != *list_len)
		{
			ft_lstclear(&first, free);
			ft_exit_error("Error: failure initing a stack!\n", EXIT_FAILURE);
		}
	}
	return (first);
}

void	ft_init_stack_a(char **av, t_stackinfo *info)
{
	int	arg_len;
	int	*nums;

	arg_len = 0;
	nums = ft_check_args(av, &arg_len);
	info->stack = ft_init_list(nums, arg_len, &info->stack_len);
	if (!info->stack)
		ft_exit_error("Error: parsing arguments!\n", EXIT_FAILURE);
}

void	ft_printstack(t_list *stack)
{
	t_list	*curr;

	curr = stack;
	while (curr)
	{
		printf("%d\n", *(int *)curr->content);
		curr = curr->next;
	}
}

int	main(int ac, char **av)
{
	t_stackinfo	a_stack;
	t_stackinfo	b_stack;
	int			tst;
	int			tst2;

	tst2 = 55;
	tst = 69;
	if (ac == 2)
	{
		ft_init_stack_a(av, &a_stack);
		b_stack.stack = ft_lstnew(&tst);
		ft_lstadd_back(&b_stack.stack, ft_lstnew(&tst2));
		// ft_push_stack(&a_stack.stack, &b_stack.stack, TRUE);
		ft_printstack(a_stack.stack);
		printf("\n\n");
		ft_printstack(b_stack.stack);
		// ft_swap_stack(&a_stack);
		// ft_rotate_stack(&a_stack, FALSE);
		/*printf("\n\n");
		ft_printstack(a_stack.stack);
		ft_rotate_stack(&a_stack, TRUE);
		printf("\n\n");
		ft_printstack(a_stack.stack);*/
	}
	// list = ft_convert_args(av);
}
