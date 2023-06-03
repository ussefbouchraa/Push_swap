/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:21:56 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/01 22:25:53 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

