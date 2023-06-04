/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:24:05 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/03 21:52:33 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_args(char **args)
{
	int	i;
	int	j;

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
