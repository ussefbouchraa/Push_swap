/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:59:06 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/09 18:25:45 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_args(char **av, int words)
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

void	check_args(char **args)
{
	int i;
	int j;

	i = -1;
	while (args[++i])
	{
		if (!ft_isdigit(args[i]))
			ft_clear(args);
		if ((ft_atoi(args[i]) > INT_MAX) || (ft_atoi(args[i]) < INT_MIN) )
			ft_clear(args);
		j = i;	
		while (args[++j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				ft_clear(args);
		}
		printf("%ld\n",ft_atoi(args[i]));
	}
}
int	main(int ac, char **av)
{
	
	char **args;
	int words;

	words = 0;

	if (ac < 2)
		return (0);
	words = nbr_args(av);
	args = split_args(av, words);
	check_args(args);

}
