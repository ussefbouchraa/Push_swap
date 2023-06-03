/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_instructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 04:33:50 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/02 23:52:53 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    ss(t_list *lst_a, t_list *lst_b, int msg)
{
    sa(lst_a, 0);
    sa(lst_b, 0);
    if (msg)
    write(1,"ss\n",3);
}

void    rr(t_list **lst_a, t_list **lst_b, int msg)
{
    ra(lst_a, 0);
    ra(lst_b, 0);
    if (msg)
     write(1, "rr\n", 3);
}

void    rrr(t_list **lst_a, t_list **lst_b, int msg)
{
    rra(lst_a, 0);
    rra(lst_b, 0);
    if (msg)
    write(1, "rrr\n", 4);
}