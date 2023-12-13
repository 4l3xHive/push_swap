/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:42:07 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/13 16:04:25 by apyykone         ###   ########.fr       */
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

int	*ft_check_args(char **av, size_t *len)
{
	int 	num;
	size_t 	i;
	int 	*nums;

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
	int	i;
	t_list *first;

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
			ft_exit_error("Error: failure creating the stack!\n", EXIT_FAILURE);
		}
	}
	return (first);
}

void ft_init_stack(char **av, t_stackinfo *info)
{
	size_t 	arg_len;

	arg_len = 0;
	info->stack = ft_init_list(ft_check_args(av, &arg_len), arg_len, &info->len);
	if (!info->stack)
		ft_exit_error("Error: parsing arguments!\n", EXIT_FAILURE);

}

void ft_printstack(t_list *stack)
{
	t_list *curr;

	curr = stack;

	while (curr)
	{
		printf("%d\n", *(int *)curr->content);
		curr = curr->next;
	}

}


int main(int ac, char **av)
{
	t_stackinfo	a_stack;

	if (ac == 2)
	{
		ft_init_stack(av, &a_stack);
		ft_printstack(a_stack.stack);
		ft_rotate_stack(&a_stack);
		//ft_swap_stack(&a_stack);
		printf("\n\n");
		ft_printstack(a_stack.stack);
	}
	//list = ft_convert_args(av);
	
}