/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:26:35 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/31 21:37:49 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_max(t_list *lst)
{
    int max;
    
    max = lst->content;
    while(lst)
    {
        if(lst->content > max)
            max = lst->content;
        lst = lst->next;
    }
    return(max);
}

int ft_pos_max(t_list *lst)
{
    int max;
    
    max = lst->pos;
    while(lst)
    {
        if(lst->pos > max)
            max = lst->pos;
        lst = lst->next;
    }
    return(max);
}