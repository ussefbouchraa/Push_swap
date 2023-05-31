/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:00:41 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/30 18:01:04 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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