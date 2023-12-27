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

/* Init both main structures*/
void	ft_init_all(t_stackinfo *a, t_stackinfo *b, t_index *i, t_sort3 *c)
{
	if (!i && !c)
	{
		a->nums = NULL;
		a->stack = NULL;
		a->curr_stack_len = 0;
		b->stack = NULL;
		b->nums = NULL;
		b->curr_stack_len = 0;
	}
	if (i)
	{
		i->i = 0;
		i->smallest_content = INT_MAX;
		i->smallest_index = -1;
		i->is_sorted = FALSE;
	}
	if (c && a)
	{
		c->first = *(int *)(a->stack->content);
		c->second = *(int *)(a->stack->next->content);
		c->third = *(int *)(a->stack->next->next->content);
	}
}

void	ft_check_and_convert_args(char **av, t_stackinfo *a)
{
	char	**nums;
	size_t	i;

	i = 0;
	if (av[1] && av[2])
		nums = av + 1;
	else
	{
		nums = ft_split(av[1], ' ');
		if (!nums)
			ft_exit(a, NULL, 0);
	}
	while (nums[i])
		i++;
	a->curr_stack_len = i;
	a->nums = (int *)malloc(sizeof(int) * i);
	if (a->nums == NULL)
		ft_exit(a, NULL, 0);
	i = 0;
	while (nums[i] && ft_check_valid(nums[i]))
	{
		a->nums[i] = ft_atoi(nums[i]);
		i++;
	}
	if (av[1] && av[2])
		ft_freeall(nums, (long)a->curr_stack_len, NULL, NULL);
	if (i != a->curr_stack_len)
		ft_exit(a, NULL, 0);
}

/* Converts arguments to ints*/
void	ft_check_args(char **av, t_stackinfo *a)
{
	size_t	i;

	i = 0;
	while (av[i + 1])
		i++;
	a->curr_stack_len = i;
	a->nums = (int *)malloc(sizeof(int) * i);
	if (a->nums == NULL)
		ft_exit(a, NULL, 0);
	i = 0;
	while (av[i + 1] && ft_check_valid(av[i + 1]))
	{
		a->nums[i] = ft_atoi(av[i + 1]);
		i++;
	}
	if (i != a->curr_stack_len)
		ft_exit(a, NULL, 0);
}

/*Inits the linkedlist stack for a*/
void	ft_init_stack_a(t_stackinfo *a)
{
	size_t	i;
	t_list	*temp;

	i = 0;
	temp = NULL;
	while (i < a->curr_stack_len)
	{
		temp = ft_lstnew(&a->nums[i++]);
		if (!temp)
			ft_exit(a, NULL, 0);
		ft_lstadd_back(&a->stack, temp);
	}
}

/* Need to create diff vals for error checking in printf in upper levels
works as a callback also if there is pf_callback enabled*/
void	ft_exit(t_stackinfo *a, t_stackinfo *b, int err)
{
	if (err > 0)
		return ;
	ft_freeall(NULL, 0, a, b);
	if (err <= 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	ft_freeall(char **split, long split_i, t_stackinfo *a, t_stackinfo *b)
{
	if (split)
	{
		while (split_i >= 0)
			free(split[split_i--]);
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
}
