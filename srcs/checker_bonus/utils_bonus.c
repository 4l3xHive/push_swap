/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:47:36 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/18 01:47:37 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

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
	if (ft_str_isdigit(str) == FALSE)
		return (FALSE);
	val = ft_atol(str);
	return (val >= INT_MIN && val <= INT_MAX);
}

// Checks that if the stack is sorted || unqiue
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
