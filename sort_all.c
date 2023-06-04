/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:42:11 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/04 01:47:16 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_b(t_list **lst_b, t_list **lst_a, int chnk, int demi_chnk)
{
	if ((*lst_b && *lst_a) && (*lst_b)->pos <= demi_chnk
		&& (*lst_a)->pos >= chnk)
		rr(lst_a, lst_b, 1);
	else if ((*lst_b)->pos <= demi_chnk)
		ra(lst_b, 2);
}

// [3, 4, 10, 5, 1, 0, 9]
// [0, 1, 2,  3, 4, 5, 6]

// size = 7/2 = 3;
// max = 10, pos1 = 2;
// umax = 9, pos2 = 6;
// max in top of stack => ra => cost = pos1 = 2
// undermax in bottom of stack => rra => cost = size - pos2 = 1

int	closest(int pos1, int pos2, int size)
{
	int	ds;
	int	cost1;
	int	cost2;

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
	int	pos1;
	int	pos2;
	int	i;

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
	return (closest(pos1, pos2, size));
}

int	min_instruction(t_list *lst_b, int max, int size)
{
	int	demi_size;

	demi_size = size / 2;
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

void	ft_pa(t_list **lst_a, t_list **lst_b)
{
	int	max;
	int	size;

	size = ft_lstsize(*lst_b);
	while (*lst_b)
	{
		max =  ft_pos_max(*lst_b);
		if (get_closiest(*lst_b, max - 1, max, size) == 1)
		{
			if (min_instruction(*lst_b, max, size)) // check if the max in the top half of B
			{
				while ((*lst_b)->pos != max)
					ra(lst_b, 2);
			}
			else{ // max in bottom half of B
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
	}
}
