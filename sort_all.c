/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:42:11 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/05 01:43:40 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	closest(int indx_mx, int indx_um, int size)
{
	int	ds;
	int	cost1;
	int	cost2;

	ds = size / 2;
	if (indx_um == -1)
		return (1);
	if (indx_mx > ds)
		cost1 = size - indx_mx;
	else
		cost1 = indx_mx;
	if (indx_um > ds)
		cost2 = size - indx_um;
	else
		cost2 = indx_um;
	return (cost1 <= cost2);
}

int	get_closiest(t_list *lst, int um, int mx, int size)
{
	int	indx_mx;
	int	indx_um;
	int	i;

	i = 0;
	indx_um = -1;
	while (lst)
	{
		if (lst->pos == mx)
			indx_mx = i;
		if (lst->pos == um)
			indx_um = i;
		i++;
		lst = lst->next;
	}
	return (closest(indx_mx, indx_um, size));
}

void	under_max(t_list **lst_a, t_list **lst_b, int max, int size)
{
	if (min_instruction(*lst_b, max - 1, size))
	{
		while ((*lst_b)->pos != max - 1)
			ra(lst_b, 2);
	}
	else
	{
		while ((*lst_b)->pos != max - 1)
			rra(lst_b, 2);
	}
	pa(lst_a, lst_b, 1);
}

void	l_max(t_list **lst_a, t_list **lst_b, int max, int size)
{
	if (min_instruction(*lst_b, max, size))
	{
		while ((*lst_b)->pos != max)
			ra(lst_b, 2);
	}
	else
	{
		while ((*lst_b)->pos != max)
			rra(lst_b, 2);
	}
	pa(lst_a, lst_b, 1);
}

void	ft_pa(t_list **lst_a, t_list **lst_b)
{
	int	max;
	int	size;

	size = ft_lstsize(*lst_b);
	while (*lst_b)
	{
		max = ft_pos_max(*lst_b);
		if (get_closiest(*lst_b, max - 1, max, size))
		{
			l_max(lst_a, lst_b, max, size);
			if ((*lst_a)->next && (*lst_a)->content > (*lst_a)->next->content)
				sa(*lst_a, 1);
		}
		else
			under_max(lst_a, lst_b, max, size);
		size--;
	}
}
