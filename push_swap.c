/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:59:06 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/03 00:08:40 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void instructs(t_list **lst_a, t_list **lst_b, int size)
{
	if (!(ft_issorted(*lst_a)))
	{
		if (size == 2)
			sa(*lst_a, 1);
		else if (size == 3)
			sort_of_three(lst_a, ft_max(*lst_a), ft_min(*lst_a));
		else if (size == 4)
			sort_of_four(lst_a, lst_b, ft_min(*lst_a));
		else if (size == 5)
			sort_of_five(lst_a, lst_b, ft_min(*lst_a));
		else
			sort_all(lst_a, lst_b, size);
	}
	
}

int get_min(t_list *lst)
{
	int min;

	min = ft_max(lst);
	while (lst)
	{
		if (lst->content < min && lst->pos == -1)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

void init_pos(t_list *lst_a)
{
	t_list *container;
	t_list *loop;
	int pos;

	pos = -1;

	loop = lst_a;
	while (loop)
	{
		container = lst_a;
		while (container->content != get_min(lst_a))
			container = container->next;
		container->pos = ++pos;

		loop = loop->next;
	}
}

void ll()
{
	system("leaks push_swap");
}
int main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**args;
	int		words;
	int 	i;

	lst_a = NULL;
	lst_b = NULL;
	
	if (ac < 2)
		return (0);
	words = nbr_args(av);
	args = split_args(av, words); 
	check_args(args); 
	i = -1;
	while (args[++i])
	{
		ft_lstadd_back(&lst_a, ft_lstnew((int)ft_atoi(args[i])));
		free(args[i]);
	}
	free(args);
	init_pos(lst_a);
	instructs(&lst_a, &lst_b, ft_lstsize(lst_a));		
	free_lnkedlist(&lst_a);
	free_lnkedlist(&lst_b);
}

