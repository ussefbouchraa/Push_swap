/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 04:15:34 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/24 04:17:54 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_of_three(t_list **lst, int max, int min)
{

    if ((*lst)->content == max)
        {
            if (((*lst)->next)->content == min)
                ra(*lst, 1);
            else
            {
                sa(*lst, 1);
                rra(lst, 1);
            }
        }
    else if ((*lst)->next->next->content == max)
        sa(*lst, 1);
    else if ((*lst)->next->next->content == min)
        rra(lst, 1);

    else if ((*lst)->content == min)
    {
        sa(*lst, 1);
        ra(*lst, 1);
    }
}

void	sort_of_five(t_list **lst_a, t_list **lst_b)
{
	int min;
	min = ft_min(*lst_a);

	while(ft_lstsize(*lst_a) > 3)
	{
		if((*lst_a)->content == min)
		{
			pb(lst_a, lst_b, 1);
			min = ft_min(*lst_a);
		}
		else
			ra(*lst_a, 1);
	}
	if(!(ft_issorted(*lst_a)))
		sort_of_three(lst_a, ft_max(*lst_a), ft_min(*lst_a));
	while (*lst_b)
		pa(lst_a, lst_b, 1);
}

void ft_print(t_list *lst_a, t_list *lst_b)
{
	printf("\n___STACK A:___\n");
	while (lst_a)
	{
		printf("     %d\n", lst_a->content);
		lst_a = lst_a->next;
	}
	
	printf("\n___STACK B:___\n");
	while (lst_b)
	{
		printf("     %d\n", lst_b->content);
		lst_b = lst_b->next;
	}
}