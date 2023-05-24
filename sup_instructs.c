/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_instructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 04:33:50 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/24 04:36:59 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_list **lst_a, t_list **lst_b, int msg)
{
    if (!*lst_b)
        return;

    ft_lstadd_front(lst_a, ft_lstnew((*lst_b)->content));
    *lst_b = (*lst_b)->next;

    if(msg == 1)
        write(1, "pa\n", 3);
}

void    pb(t_list **lst_a, t_list **lst_b, int msg)
{
    if (!*lst_a)
        return;

    ft_lstadd_front(lst_b, ft_lstnew((*lst_a)->content));
    *lst_a = (*lst_a)->next;

    if(msg == 1)
        write(1, "pb\n", 3);
}
void    ss(t_list *lst_a, t_list *lst_b)
{
    sa(lst_a, 0);
    sb(lst_b, 0);
    write(1,"ss\n",4);
}

void    rr(t_list *lst_a, t_list *lst_b)
{
    ra(lst_a, 0);
    rb(lst_b, 0);
     write(1, "rr\n", 3);
}

void    rrr(t_list **lst_a, t_list **lst_b)
{
    rra(lst_a, 0);
    rrb(lst_b, 0);
    write(1, "rrr\n", 4);
}