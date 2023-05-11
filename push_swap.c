/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:59:06 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/11 23:24:38 by ybouchra         ###   ########.fr       */
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
		spl = ft_split(av[i], ' ');
		j = 0;
		while (spl[j])
			args[x++] = spl[j++];
		free(spl);
	}
	args[x] = NULL;

	return (args);
}

int	ft_valid_size(char *arg)
{
	int i;
	int len;

	len = 0;
	i = -1;

	while (arg[++i] == '0')
		len++;
	if (arg[i] != '0' && arg[i])
		arg = arg + len;
	
	if (((ft_atoi(arg) > INT_MAX) || (ft_atoi(arg) < INT_MIN)) 
		|| ft_strlen(arg) > 11)
		return(0);

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

int	main(int ac, char **av)
{
	
	char **args;
	int words;
	int i = -1;

	words = 0;

	if (ac < 2)
		return (0);
	words = nbr_args(av);
	args = split_args(av, words);
	check_args(args);
	
	while(args[++i])
		printf("%d\n",atoi(args[i]));
}
