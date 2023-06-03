/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:31:28 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/03 20:09:26 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void ft_clear(char **arr)
// {
//     int i;

//     i = -1;
//     write(2, "ERROR", 6);
//     while (arr[++i])
//         free(arr[i]);
//     free(arr);
//     arr = NULL;
//     exit(1);
// }

void    free_lnkedlist(t_list **lst)
{
    t_list *temp;

    if (!lst || !*lst)
        return;

    while (*lst)
    {
        temp = *lst;
        *lst = (*lst)->next;
        free(temp);
    }
}