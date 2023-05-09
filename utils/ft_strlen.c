/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 05:48:24 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/06 05:50:41 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

size_t  ft_strlen(const char *s)
{
    int len;
    
    len = 0;
    while (*s)
    {
        len++;
        s++;
    }
    return len;
}