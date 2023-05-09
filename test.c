/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:28:51 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/08 13:44:27 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_of_args(char **av)
{
	int i = 0;
	int j;
	int word = 0;

	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] != ' ') &&
			(av[i][j + 1] == '\0' || av[i][j + 1] == ' '))
				word++;
		}
	}
	return (word);
}

int	main(int ac, char **av)
{
	int count;
	if (ac < 2)
	{
		printf("ERROR");
		exit(0);
	}
	count = nbr_of_args(av);
	printf("%d", count);
}