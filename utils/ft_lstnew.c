/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:41:01 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/21 00:09:05 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void *ft_lstnew(int content)
{
	t_list *head;
   
	head = malloc(sizeof(t_list));
	if(!head)
		return(NULL);
		
	head->content = content;
	head->next = NULL;
	return head;
}