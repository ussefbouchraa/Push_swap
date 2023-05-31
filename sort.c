/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 04:15:34 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/31 21:37:56 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_of_three(t_list **lst, int max, int min)
{

    if ((*lst)->content == max)
        {
            if (((*lst)->next)->content == min)
                ra(lst, 1);
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
        ra(lst, 1);
    }
}

void	sort_of_four(t_list **lst_a, t_list **lst_b, int min)
{
	if ((*lst_a)->next->next->next->content == min)
			rra(lst_a, 1);
			
	while((*lst_a)->content != min)
		ra(lst_a, 1);
	pa(lst_b, lst_a, 2);

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
		ra(lst_a, 1);
	pa(lst_b, lst_a, 2);
	
	if(!(ft_issorted(*lst_a)))
		sort_of_four(lst_a, lst_b, ft_min(*lst_a));
	pa(lst_a, lst_b, 1);
} 

void	ft_check_b(t_list **lst_b , int demi_chnk, t_list **lst_a, int chnk)
{
	if ((*lst_b  && *lst_a) && (*lst_b)->pos <= demi_chnk && (*lst_a)->pos >= chnk)
		rr(lst_a, lst_b, 1);
	else if((*lst_b)->pos <= demi_chnk)
		ra(lst_b, 2);
}

int	min_instruction(t_list *lst_b, int max, int size)
{
	int demi_size = size / 2;
	while (lst_b)
	{
		if (lst_b->pos == max)
			return (1);
		if (demi_size-- == 0)
			return (0);
		lst_b = lst_b->next;
	}
	return (0);
}

// void ft_pa(t_list **lst_a, t_list **lst_b )
// {
// 	int size;
// 	size = ft_lstsize(*lst_b);
	
// 	while (*lst_b)
// 	{
// 		int max =  ft_max(*lst_b);
// 		if ((*lst_b)->content == max)
// 		{
// 			pa(lst_a, lst_b, 1);
// 			size--;
// 		}
// 		else if (min_instruction(*lst_b, max, size))
// 				ra(lst_b, 2);
// 		else
// 			rra(lst_b, 2);
// 	}
// }



// top[22, 34 , 234 ,4543, 566 343325, 56, 2334, 45456, 2323 , 455] 
int closest(int pos1, int pos2, int size)
{
	int ds;
	int cost1;
	int cost2;
	
	ds = size / 2;
	if (pos2 == -1)
		return (1);
	if (pos1 > ds)
		cost1 = size - pos1;
	else 
		cost1 = pos1;
	if (pos2 > ds)
		cost2 = size - pos2;
	else
		cost2 = pos2;
	return (cost1 <= cost2);
}

int	get_closiest(t_list *lst, int um, int mx, int size)
{
	int pos1;
	int pos2;
	int i;

	i = 0;
	pos2 = -1;
	while (lst)
	{
		if (lst->pos == mx)
			pos1 = i;
		if (lst->pos == um)
			pos2 = i;
		i++;
		lst = lst->next;
	}
	// printf("pos1 %d, pos2 %d\n", pos1, pos2);
	return (closest(pos1, pos2, size));
}
void ft_pa(t_list **lst_a, t_list **lst_b)
{
	int max;
	int size;
	int x;
	size = ft_lstsize(*lst_b);
	while (*lst_b)
	{
		max =  ft_pos_max(*lst_b);
		if ((x = get_closiest(*lst_b, max - 1, max, size)))
		{
			// printf("x:%d\n", x);
			if (min_instruction(*lst_b, max, size))
			{
				while ((*lst_b)->pos != max)
					ra(lst_b, 2);
			}
			else{
				while ((*lst_b)->pos != max)
					rra(lst_b, 2);
			}
			pa(lst_a, lst_b, 1);
			size--;
			if ((*lst_a)->next && (*lst_a)->content > (*lst_a)->next->content)
				sa(*lst_a, 1);
		}
		else
		{
			if (min_instruction(*lst_b, max - 1, size))
			{
				while ((*lst_b)->pos != max - 1)
					ra(lst_b, 2);
			}
			else{
				while ((*lst_b)->pos != max - 1)
					rra(lst_b, 2);
			}
			pa(lst_a, lst_b, 1);
			size--;
		}
		// exit(0);
	}
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
		if((*lst_a)->pos <= chnk)
		{
			pa(lst_b, lst_a, 2);
			size--;
			stack_b++;
			ft_check_b(lst_b ,chnk - (one_chnk / 2), lst_a, chnk);
			if( stack_b == chnk)
				chnk += one_chnk;
		}
		else
			ra(lst_a, 1);	
	}
	ft_pa(lst_a, lst_b);
}

	// 56 12/6
// top[22, 34 , 234 ,4543, 566 343325, 56, 2334, 45456, 2323 , 455] => 12
// 5 4 3 2 1 