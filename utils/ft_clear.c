/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:31:28 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/18 20:05:21 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_clear(char **arr)
{
    int i;
    
    i = -1;
	write(2, "ERROR", 6);
    while (arr[++i])
        free(arr[i]);
    free(arr);
    arr = NULL;
    exit(1);
}
