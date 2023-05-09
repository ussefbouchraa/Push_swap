/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 05:26:59 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/09 17:13:29 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long ft_atoi(char *s)
{
    long res;
    int sign;

    res = 0;
    sign = 1;
    if (!*s)
    {
        write(2, "ERROR", 5);
        exit(1);
    }
    if (*s == ' ' || (*s >= 9 && *s <= 13))
        s++;

    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign *= -1;
        s++;
    }
    while(*s && (*s >= '0' && *s <= '9' ))
    {
            res = res * 10 + *s - '0';
               s++;
    }
    return (sign * res);
}