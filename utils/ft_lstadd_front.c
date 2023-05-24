/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:39:32 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/21 00:15:51 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
  if (!new || !lst)
    return ;
  new->next = *lst;
  *lst = new;
}
