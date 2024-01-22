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

/**
 * @brief Init function for initializing structs, able to init only one also
 * 	@param a pointer to a stack info
 * 	@param b pointer to b stack info
 * 	@param i pointer to an index
 * 	@param c pointer to a sort3 struct
 */
void	ft_init_helpers(t_stackinfo *a, t_index *i, t_sort3 *c)
{
	if (i)
	{
		i->i = 0;
		i->found_content = INT_MAX;
		i->found_index = -1;
		i->is_sorted = FALSE;
		i->middle_index = 0;
	}
	if (c && a)
	{
		c->first = *(int *)(a->stack->content);
		c->second = *(int *)(a->stack->next->content);
		c->third = *(int *)(a->stack->next->next->content);
	}
}

/**
 * @brief Checks if the given arguments are a valid integers.
 * 	@param av argument vector
 * 	@param a pointer to a stack info
 * 	@param i pointer to an index
 * 	@param nums pointer to a string array
 */
void	ft_check_and_convert_args(char **av, t_stackinfo *a, t_index *i,
		char **nums)
{
	if (av[1] && av[2])
		nums = av + 1;
	else
	{
		nums = ft_split(av[1], ' ');
		if (!nums)
			ft_exit(a, NULL, -1);
	}
	while (nums[i->i])
		i->i++;
	a->curr_stack_len = i->i;
	a->nums = (int *)malloc(sizeof(int) * i->i);
	if (a->nums == NULL)
		ft_exit(a, NULL, -1);
	i->i = 0;
	while (nums[i->i])
	{
		if (ft_check_valid_int(nums[i->i]))
			a->nums[i->middle_index++] = ft_atoi(nums[i->i]);
		i->i++;
	}
	if (av[1] && av[2] == NULL)
		ft_freeall(nums, (long)a->curr_stack_len, NULL, NULL);
	if ((size_t)i->middle_index != a->curr_stack_len)
		ft_exit(a, NULL, -1);
}

static void	create_index(t_stackinfo *a, t_index *i, t_list *current)
{
	current = a->stack;
	while (i->i < a->curr_stack_len)
	{
		i->found_index = 0;
		i->found_content = a->nums[i->i];
		i->j = 0;
		while (i->j < a->curr_stack_len)
		{
			if (i->found_content > a->nums[i->j])
				i->found_index++;
			i->j++;
		}
		while (current)
		{
			if (*(int *)current->content == i->found_content)
			{
				current->index = i->found_index;
				break ;
			}
			current = current->next;
		}
		current = a->stack;
		i->i++;
	}
}

/**
* @brief Initializes stack a with the given arguments and
		creates indexes for each node.
 * 	@param a pointer to a stack info
 * 	@param i pointer to an index
 */
void	ft_init_stack_a(t_stackinfo *a, t_index *i)
{
	t_list	*temp;

	i->i = 0;
	temp = NULL;
	while (i->i < a->curr_stack_len)
	{
		temp = ft_lstnew(&a->nums[i->i++]);
		if (!temp)
			ft_exit(a, NULL, -1);
		ft_lstadd_back(&a->stack, temp);
	}
	ft_init_helpers(NULL, i, NULL);
	create_index(a, i, temp);
}

/**
 * @brief Frees all allocated memory or some of it depending on the arguments.
 * 	@param split pointer to a string array
 * 	@param s_i max index for the string array
 * 	@param a pointer to a stack info
 * 	@param b pointer to b stack info
 */
void	ft_freeall(char **split, long s_i, t_stackinfo *a, t_stackinfo *b)
{
	if (split)
	{
		while (s_i >= 0)
			free(split[s_i--]);
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
