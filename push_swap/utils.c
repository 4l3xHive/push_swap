/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:47:36 by apyykone          #+#    #+#             */
/*   Updated: 2024/01/02 04:22:03 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Compares the first integer to the second.
 * @param a pointer to the first integer
 * @param b pointer to the second integer
 */
int	ft_intcmp(const void *a, const void *b)
{
	int	int_a;
	int	int_b;

	int_a = *(int *)a;
	int_b = *(int *)b;
	if (int_a < int_b)
		return (-1);
	else if (int_a > int_b)
		return (1);
	else
		return (0);
}

/**
 * @brief Checks if the given string is a valid integer.
 * @param str pointer to a string
 */
int	ft_check_valid_int(const char *str)
{
	long	val;
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0' || ft_isdigit(str[i]) == FALSE)
		return (FALSE);
	while (str[i])
	{
		if (ft_isdigit(str[i++]) == FALSE)
			return (FALSE);
	}
	val = ft_atol(str);
	return (val >= INT_MIN && val <= INT_MAX);
}

/**
 * @brief Checks if the stack is sorted or unique.
 * @param stack pointer to a stack
 * @param check_unique TRUE checks if the stack is unique.
 *  FALSE, checks if stacks is sorted.
 */
int	ft_is_sorted_or_unique(t_list *stack, int check_unique)
{
	t_list	*current;
	t_list	*runner;

	current = stack;
	while (current && current->next)
	{
		if (!check_unique
			&& *(int *)current->content > *(int *)current->next->content)
			return (FALSE);
		runner = current->next;
		while (check_unique && runner)
		{
			if (*(int *)current->content == *(int *)runner->content)
				return (FALSE);
			runner = runner->next;
		}
		current = current->next;
	}
	return (TRUE);
}
