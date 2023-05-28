/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_instructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 04:33:50 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/28 09:38:46 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_list **lst_a, t_list **lst_b, int msg)
{
    if (!*lst_b)
        return;
        
    t_list *tmp_a;
    t_list *tmp_b;
    
    tmp_a = *lst_a;
    tmp_b = *lst_b;
    
    *lst_a = tmp_b;

    *lst_b = (*lst_b)->next;
    tmp_b->next = tmp_a;
    
    if (msg == 1)
        write(1, "pa\n", 3);
}

void    pb(t_list **lst_a, t_list **lst_b, int msg)
{
    if (!*lst_a)
        return;
  t_list *tmp_a;
  t_list *tmp_b;
  
    tmp_a = *lst_a;
    tmp_b = *lst_b;
    
    *lst_b = tmp_a;

    *lst_a = (*lst_a)->next;
    tmp_a->next = tmp_b;

    if(msg == 1)
        write(1, "pb\n", 3);
}
void    ss(t_list *lst_a, t_list *lst_b)
{
    sa(lst_a, 0);
    sb(lst_b, 0);
    write(1,"ss\n",4);
}

void    rr(t_list *lst_a, t_list *lst_b, int msg)
{
    ra(lst_a, 0);
    rb(lst_b, 0);
    if (msg)
     write(1, "rr\n", 3);
}

void    rrr(t_list **lst_a, t_list **lst_b)
{
    rra(lst_a, 0);
    rrb(lst_b, 0);
    write(1, "rrr\n", 4);
}