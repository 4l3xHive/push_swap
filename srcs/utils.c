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

#include "push_swap.h"

int	ft_intcmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	ft_check_valid(const char *str)
{
	long	val;

	if (!ft_str_isdigit(str))
		return (FALSE);
	val = ft_atol(str);
	return (val >= INT_MIN && val <= INT_MAX);
}

int	ft_str_isdigit(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (FALSE);
	while (str[i])
	{
		if (ft_isdigit(str[i++]) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

long	ft_atol(const char *str)
{
	long	res;
	int		neg;
	size_t	i;

	res = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * neg);
}

// Checks that if the stack is sorted
int	ft_is_sorted_or_unique(t_list *stack, int check_unique)
{
	t_list	*current;
	t_list	*runner;

	current = stack;
	while (current != NULL && current->next != NULL)
	{
		if (!check_unique
			&& *(int *)current->content > *(int *)current->next->content)
			return (FALSE);
		runner = current->next;
		while (check_unique && runner != NULL)
		{
			if (*(int *)current->content == *(int *)runner->content)
				return (FALSE);
			runner = runner->next;
		}
		current = current->next;
	}
	return (TRUE);
}

// prints bnoth sta
void	ft_printstack(t_list *a, t_list *b)
{
	t_list *curr1;
	t_list *curr2;

	curr2 = b;
	curr1 = a;
	while (curr1 || curr2)
	{
		if (curr1)
		{
			ft_printf("%d", *(int *)curr1->content);
			curr1 = curr1->next;
		}
		if (curr2)
		{
			ft_printf("      %d", *(int *)curr2->content);
			curr2 = curr2->next;
		}
		write(1, "\n", 1);
	}
	ft_printf("|a|    |b|\n");
}