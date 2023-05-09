/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:54:50 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/08 17:10:36 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int nbr_args(char **av)
{
    int i = 0;
    int j;
    int word = 0;

    if(!av)
        return(0);

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