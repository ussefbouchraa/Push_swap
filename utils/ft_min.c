/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:42:07 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/22 23:45:03 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_min(t_list *lst)
{
    int min;
    min = lst->content;

    while(lst)
    {
        if(lst->content < min)
            min = lst->content;
        lst = lst->next;
    }
    return(min);
}