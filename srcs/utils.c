/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:30:45 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/13 16:04:27 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_swap_stack(t_stackinfo *info)
{
    void    *temp;

    if (info->len > 1)
    {
        temp = info->stack->content;
        info->stack->content = info->stack->next->content;
        info->stack->next->content = temp;
    }
    return (0);
}

// Works normal!
int ft_rotate_stack(t_stackinfo *info, int reverse)
{
    t_list  *first;
    t_list  *second;
    void    *tmp_c;

    if (info->len > 1)
    {
        first = info->stack;
        second = first->next;
        while (second)
        {
            tmp_c = first->content;
            first->content = second->content;
            second->content = tmp_c;
            second = second->next;
            first = first->next;
        }

    }
    return (0);
}
// PROTO FOR REVERSE IN SAME FUNCTION !!
int ft_rotate_stack(t_stackinfo *info, int reverse)
{
    t_list  *first;
    t_list  *second;
    void    *tmp_c;

    if (info->len > 1)
    {
        first = info->stack;
        second = first->next;
        if (reverse)
        {
            first = ft_lstlast(info->stack);
            second = info->stack;
        }
        while (second)
        {
            tmp_c = first->content;
            first->content = second->content;
            second->content = tmp_c;
            second = second->next;
            first = first->next;
        }

    }
    return (0);
}