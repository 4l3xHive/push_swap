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

/* Converts arguments to ints*/
void	ft_check_args(char **av, t_stackinfo *a)
{
	size_t	i;
	char	**split_nums;

	i = 0;
	split_nums = ft_split(av[1], ' ');
	if (!split_nums)
		ft_exit("Error\n", a, NULL, 0);
	while (split_nums[i])
		i++;
	a->curr_stack_len = i;
	a->nums = (int *)malloc(sizeof(int) * i);
	if (a->nums == NULL)
		ft_exit("Error\n", a, NULL, 0);
	i = 0;
	while (split_nums[i] && ft_check_valid(split_nums[i]))
	{
		a->nums[i] = ft_atoi(split_nums[i]);
		i++;
	}
	ft_freeall(split_nums, (long)a->curr_stack_len, NULL, NULL);
	if (i != a->curr_stack_len)
		ft_exit("Error\n", a, NULL, 0);
}

/*Inits the linkedlist stack for a*/
void	ft_init_stack_a(t_stackinfo *a)
{
	size_t	i;
	t_list	*temp;

	i = 0;
	temp = NULL;
	if (a->nums)
	{
		while (i < a->curr_stack_len)
		{
			temp = ft_lstnew(&a->nums[i++]);
			if (!temp)
				ft_exit("Error\n", a, NULL, 0);
			ft_lstadd_back(&a->stack, temp);
		}
	}
}

/* Need to create diff vals for error checking in printf in upper levels
works as a callback also if there is pf_callback enabled*/
void	ft_exit(const char *err_msg, t_stackinfo *a, t_stackinfo *b, int err)
{
	if (err == pf_err || err == -1)
		err_msg = "Error\n";
	if (err == pf_success || err == pf_success1 || err == pf_success2)
		return ;
	ft_freeall(NULL, 0, a, b);
	if (err_msg)
	{
		ft_putstr_fd((char *)err_msg, STDERR_FILENO);
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
