/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_instructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:43:22 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/05 01:43:45 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
