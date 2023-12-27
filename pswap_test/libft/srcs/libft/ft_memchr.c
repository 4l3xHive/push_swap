/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:19:08 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/12/26 13:39:21 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void *ft_memchr(const void *s, int c, size_t n) {
    size_t i;
    unsigned char *uc_s = (unsigned char *)s;

    i = 0;
    while (i < n) {
        if (uc_s[i] == (unsigned char)c)
            return ((void *)&uc_s[i]);
        i++;
    }
    return (NULL);
}

