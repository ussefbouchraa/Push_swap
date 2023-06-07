/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:21:56 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/07 05:04:02 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**split_args(char **av, int words)
{
	char	**args;
	char	**spl;
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	args = malloc(sizeof(char *) * (words + 1));
	if (!args)
		return (NULL);
	while (av[++i])
	{
		if (!av[i][0] || ft_isspace(av[i]))
			ft_clear(args);
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
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i] == '0')
		i++;
	if (ft_strlen(arg + i) > 10)
		return (0);
	if (ft_atoi(arg) < INT_MIN || ft_atoi(arg) > INT_MAX)
		return (0);
	return (1);
}
