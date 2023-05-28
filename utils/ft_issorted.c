/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:56:31 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/28 09:18:41 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_issorted(t_list *lst)
{
	t_list *container;
	int item;
	if (!lst || !lst->next)
		return (1);
	while(lst->next)
	{
		item = lst->content; 
		
		container = lst->next;
		while(container)
		{
			if(item > container->content)
			return(0);
				
			container = container->next;
		}	
		lst = lst->next;
	}
	return(1);
		
}

// [2 5 3]