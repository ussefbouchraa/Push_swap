/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:59:06 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/31 23:15:27 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **split_args(char **av, int words)
{
	char **args;
	char **spl;
	int i;
	int j;
	int x;

	i = 0;
	x = 0;
	args = malloc(sizeof(char *) * (words + 1));
	if (!args)
		return NULL;
	while (av[++i])
	{
		if (!av[i][0] || ft_isspace(av[i]))
			ft_clear(args);
			// args[x] = NULL;
		spl = ft_split(av[i], ' ');
		j = 0;
		while (spl[j])
			args[x++] = spl[j++];
		free(spl);
	}
	args[x] = NULL;
	return (args);
}

int ft_valid_size(char *arg)
{
	int i;
	int len;

	len = 0;
	i = -1;

	if (*arg == '+' || *arg == '-')
	{
		i++;
		len++;
	}
	while (arg[++i] == '0')
		len++;
	if (arg[i])
		arg = arg + len;

	if (((ft_atoi(arg) > INT_MAX) || (ft_atoi(arg) < INT_MIN)) || ft_strlen(arg) > 11)
		return (0);
	return (1);
}

void check_args(char **args)
{
	int i;
	int j;

	i = -1;
	while (args[++i])
	{
		if (!ft_isdigit(args[i]))
			ft_clear(args);
		if (!ft_valid_size(args[i]))
			ft_clear(args);
		j = i;
		while (args[++j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				ft_clear(args);
		}
	}
}

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

	// atexit(ll);
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
	// if (ft_issorted(lst_a))
	// 	write(1 ,"\nOK\n", 4);
		// ft_print(lst_a, lst_b);
}

