/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:52:11 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/24 04:36:44 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list *lst, int msg)
{
    int tmp;
    if (!lst)
        return;
    tmp = lst->content;
    lst->content = (lst->next)->content;
    (lst->next)->content = tmp;
    if(msg == 1)
        write(1,"sa\n",4);
}
void    sb(t_list *lst_b, int msg)
{
    int tmp;
    if (!lst_b)
        return;
    tmp = lst_b->content;
    lst_b->content = (lst_b->next)->content;
    (lst_b->next)->content = tmp;
    if(msg == 1)
        write(1,"sb\n",4);
}

void    ra(t_list *lst, int msg)
{
    t_list *container;

    if (!lst)
        return;
    container = lst;
    while (container->next)
    {
        sa(container, 0);
        container = container->next;
    }
    if(msg == 1)
         write(1,"ra\n",4);
}

void    rb(t_list *lst_b,int msg)
{
    t_list *container;

    if (!lst_b)
        return;
    container = lst_b;
    while (container->next)
    {
        sb(container, 0);
        container = container->next;
    }
    if(msg == 1)
        write(1,"rb\n",4);
}

void    rra(t_list **lst, int msg)
{
    t_list *container;
    t_list *last;

    if (!lst)
        return;
    container = *lst;
    while (container->next->next)
        container = container->next;

    last = container->next;
    container->next = NULL;
    
    last->next = *lst;
    *lst = last;
    if(msg == 1)
        write(1, "rra\n", 4);
}

void    rrb(t_list **lst_b, int msg)
{
    t_list *container;
    t_list *last;

    if (!lst_b)
        return;
    container = *lst_b;
    while (container->next->next)
        container = container->next;

    last = container->next;
    container->next = NULL;
    last->next = *lst_b;
    *lst_b = last;
    
    if(msg == 1)
        write(1, "rrb\n", 4);
}


