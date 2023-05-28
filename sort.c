/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 04:15:34 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/28 12:09:20 by ybouchra         ###   ########.fr       */
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

void	sort_of_four(t_list **lst_a, t_list **lst_b, int min)
{
	if ((*lst_a)->next->next->next->content == min)
			rra(lst_a, 1);
			
	while((*lst_a)->content != min)
		ra(*lst_a, 1);
	pb(lst_a, lst_b, 1);

	if(!(ft_issorted(*lst_a)))
		sort_of_three(lst_a, ft_max(*lst_a), ft_min(*lst_a));	
	pa(lst_a, lst_b, 1);
}

void	sort_of_five(t_list **lst_a, t_list **lst_b, int min)
{
	if ((*lst_a)->next->next->next->content == min)
		rra(lst_a, 1);
	if ((*lst_a)->next->next->next->next->content == min)
		rra(lst_a, 1);
			
	while((*lst_a)->content != min)
		ra(*lst_a, 1);
	pb(lst_a, lst_b, 1);
	
	if(!(ft_issorted(*lst_a)))
		sort_of_four(lst_a, lst_b, ft_min(*lst_a));
	pa(lst_a, lst_b, 1);
} 

void ft_print(t_list *lst_a, t_list *lst_b)
{
	printf("\n___STACK A:___\n");
	while (lst_a)
	{
		printf("     %d |  %d\n", lst_a->content, lst_a->pos);
		lst_a = lst_a->next;
	}
	
	printf("\n___STACK B:___\n");
	while (lst_b)
	{
		printf("     %d |  %d\n", lst_b->content, lst_b->pos);
		lst_b = lst_b->next;
	}
}

void	ft_check_b(t_list **lst_b , int demi_chnk, t_list **lst_a, int chnk)
{

printf("%d | %d\n\n",(*lst_b)->pos, demi_chnk);

	if ((*lst_b)->pos <= demi_chnk && (*lst_a)->pos >= chnk)
		rr(*lst_a, *lst_b, 1);
	else if((*lst_b)->pos <= demi_chnk)
		rb(*lst_b, 1);
	
}
void	sort_all(t_list **lst_a, t_list **lst_b, int size)
{
	int chnk;
	int stack_b;
	int one_chnk;
	
	stack_b = 0;
	chnk = size / 5;
	
	if(size >= 500)
		chnk = size / 10;
		
	one_chnk = chnk;	
	
	while(size > 0)
	{
		if((*lst_a)->pos <= chnk   ) // (0 1 2)) <= 2
		{
			pb(lst_a, lst_b, 1);
			size--;
			stack_b++;
			
			// ft_check_b(lst_b ,chnk - (one_chnk / 2), lst_a, chnk);
			if( stack_b == chnk)
			{
				break;
			chnk += one_chnk;
			}
		}
		else
			ra(*lst_a, 1);
			
	}
	// if(!(ft_issorted(*lst_a)))
	// 	sort_of_three(lst_a, ft_max(*lst_a), ft_min(*lst_a));
	// while (*lst_b)
	// 	pa(lst_a, lst_b, 1);
}