/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:25:52 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/21 21:00:08 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *container;
    if (!new || !lst)
        return;

    if (!*lst)
        *lst = new;
    else
    {
        container = *lst;
        while (container->next)
            container = container->next;

        container->next = new;
    }
}