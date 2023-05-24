/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:26:35 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/24 02:46:59 by ybouchra         ###   ########.fr       */
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