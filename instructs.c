/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:52:11 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/04 00:55:09 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *lst, int msg)
{
	int	tmp;
	int	tmp_pos;

	if (!lst)
		return ;
	tmp = lst->content;
	tmp_pos = lst->pos;
	lst->content = (lst->next)->content;
	lst->pos = (lst->next)->pos;
	(lst->next)->content = tmp;
	(lst->next)->pos = tmp_pos;
	if (msg == 1)
		write(1, "sa\n", 3);
	if (msg == 2)
		write(1, "sb\n", 3);
}

void	ra(t_list **lst, int msg)
{
	t_list	*itr;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	itr = *lst;
	(*lst) = (*lst)->next;
	itr->next = NULL;
	ft_lstadd_back(lst, itr);
	if (msg == 1)
		write(1, "ra\n", 3);
	if (msg == 2)
		write(1, "rb\n", 3);
}

void	pa(t_list **lst_a, t_list **lst_b, int msg)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (!*lst_b)
		return ;
	tmp_a = *lst_a;
	tmp_b = *lst_b;
	*lst_a = tmp_b;
	*lst_b = (*lst_b)->next;
	tmp_b->next = tmp_a;
	if (msg == 1)
		write(1, "pa\n", 3);
	if (msg == 2)
		write(1, "pb\n", 3);
}

void	rra(t_list **lst, int msg)
{
	t_list	*container;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	container = *lst;
	while (container->next->next)
		container = container->next;
	last = container->next;
	container->next = NULL;
	last->next = *lst;
	*lst = last;
	if (msg == 1)
		write(1, "rra\n", 4);
	if (msg == 2)
		write(1, "rrb\n", 4);
}
