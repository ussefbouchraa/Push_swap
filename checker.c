/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:02:35 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/03 17:33:40 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void    exec_intrac(t_list **lst_a, t_list **lst_b, char *line)
{
    if (!ft_strcmp("sa\n", line))
        sa(*lst_a, 0);
    else if (!ft_strcmp("sb\n", line))
        sa(*lst_b, 0);
    else if (!ft_strcmp("ss\n", line))
        ss(*lst_a, *lst_b, 0);
    else if (!ft_strcmp("ra\n", line))
        ra(lst_a, 0);
    else if (!ft_strcmp("rb\n", line))
        ra(lst_b, 0);
    else if (!ft_strcmp("rr\n", line))
        rr(lst_a, lst_b, 0);
    else if (!ft_strcmp("rra\n", line))
        rra(lst_a, 0);
    else if (!ft_strcmp("rrb\n", line))
        rra(lst_b, 0);
    else if (!ft_strcmp("pa\n", line))
        pa(lst_a, lst_b, 0);
    else if (!ft_strcmp("pb\n", line))
        pa(lst_b, lst_a, 0);
    else
    {
        write(1, "Error\n", 6);
        exit(1);
    }
}

void    do_instructs(t_list **lst_a, t_list **lst_b)
{
    char *line;

    line = get_next_line(0);
    while (line)
    {
        if (!ft_strcmp("rrr\n", line))
            rrr(lst_a, lst_b, 0);
        exec_intrac(lst_a, lst_b, line);
        line = get_next_line(0);
        free(line);
    }

    if (ft_issorted(*lst_a) && !*lst_b)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}

int main(int ac, char **av)
{
    t_list *lst_a;
    t_list *lst_b;
    int words;
    int i;
    char **args;

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
    do_instructs(&lst_a, &lst_b);

    free_lnkedlist(&lst_a);
    free_lnkedlist(&lst_b);
}
//
