/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:21:43 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/17 22:21:44 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_null_init(t_stackinfo *a, t_stackinfo *b)
{
	a->nums = NULL;
	a->stack = NULL;
	a->stack_len = 0;
	b->stack = NULL;
	b->nums = NULL;
	b->stack_len = 0;
}
/* Converts arguments to ints*/
int	ft_check_args(char **av, t_stackinfo *a)
{
	size_t	i;
	char	**split_nums;

	i = 0;
	split_nums = ft_split(av[1], ' ');
	if (!split_nums)
		return (-1);
	while (split_nums[i])
		i++;
	a->stack_len = i;
	a->nums = (int *)malloc(sizeof(int) * i);
	if (a->nums == NULL)
		return (ft_freeall(split_nums, i, NULL, NULL));
	i = 0;
	while (split_nums[i])
	{
		a->nums[i] = ft_atoi(split_nums[i]);
		i++;
	}
	ft_freeall(split_nums, i, NULL, NULL);
	return (0);
}
/*Inits the linkedlist stack for a*/
int	ft_init_stack_a(t_stackinfo *a)
{
	size_t	i;
	t_list	*temp;

	i = 0;
	temp = NULL;
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

/* Need to create diff vals for error checking in printf in upper levels works as a callback also if there is pf_callback enabled*/
void	ft_exit(const char *err_msg, t_stackinfo *a, t_stackinfo *b, int pf)
{
	if (pf == pf_err || pf == -1)
		err_msg = "ERROR: printf failed !";
	if (pf == pf_success || pf == pf_success1 || pf == pf_success2)
		return ;
	ft_freeall(NULL, 0, a, b);
	if (err_msg)
	{
		ft_putstr_fd((char *)err_msg, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}

int	ft_freeall(char **split, size_t split_i, t_stackinfo *a, t_stackinfo *b)
{
	size_t	i;

	i = 0;
	if (split)
	{
		while (i < split_i)
			free(split[i++]);
		free(split);
	}
	if (a)
	{
		free(a->nums);
		ft_lstclear(&a->stack, NULL);
	}
	if (b)
	{
		free(b->nums);
		ft_lstclear(&b->stack, NULL);
	}
	return (1);
}
