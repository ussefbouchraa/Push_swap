/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 04:15:34 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/05 01:45:19 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_of_three(t_list **lst, int max, int min)
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
	while ((*lst_a)->content != min)
		ra(lst_a, 1);
	pa(lst_b, lst_a, 2);
	if (!(ft_issorted(*lst_a)))
		sort_of_three(lst_a, ft_max(*lst_a), ft_min(*lst_a));
	pa(lst_a, lst_b, 1);
}

void	sort_of_five(t_list **lst_a, t_list **lst_b, int min)
{
	if ((*lst_a)->next->next->next->content == min)
		rra(lst_a, 1);
	if ((*lst_a)->next->next->next->next->content == min)
		rra(lst_a, 1);
	while ((*lst_a)->content != min)
		ra(lst_a, 1);
	pa(lst_b, lst_a, 2);
	if (!(ft_issorted(*lst_a)))
		sort_of_four(lst_a, lst_b, ft_min(*lst_a));
	pa(lst_a, lst_b, 1);
}

void	sort_all(t_list **lst_a, t_list **lst_b, int size)
{
	int	chnk;
	int	stack_b;
	int	one_chnk;

	stack_b = 0;
	chnk = size / 5;
	if (size >= 500)
		chnk = size / 10;
	one_chnk = chnk;
	while (size > 0)
	{
		if ((*lst_a)->pos <= chnk)
		{
			pa(lst_b, lst_a, 2);
			size--;
			stack_b++;
			if ((*lst_b)->pos <= chnk - (one_chnk / 2))
				ra(lst_b, 2);
			if (stack_b == chnk)
				chnk += one_chnk;
		}
		else
			ra(lst_a, 1);
	}
	ft_pa(lst_a, lst_b);
}
