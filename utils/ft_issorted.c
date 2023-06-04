/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:56:31 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/03 22:01:31 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_issorted(t_list *lst)
{
	int		item;
	t_list	*container;

	if (!lst || !lst->next)
		return (1);
	while (lst->next)
	{
		item = lst->content;
		container = lst->next;
		while (container)
		{
			if (item > container->content)
				return (0);
			container = container->next;
		}
		lst = lst->next;
	}
	return (1);
}
