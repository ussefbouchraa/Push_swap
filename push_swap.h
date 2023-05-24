/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:49:37 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/24 01:42:35 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648



typedef struct s_stack1
{
    int content;
    struct s_stack1 *next;
}   t_list;


int     ft_isdigit(char *s);
int     ft_isspace(char *s);
int     ft_issorted(t_list *lst);
int     ft_max(t_list *lst);
int     ft_min(t_list *lst);
long	ft_atoi(char *s);
char	**ft_split(const char *str, char c);
size_t  ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strdup(const char *s);

void    ft_clear(char **arr);
int     nbr_args(char **av);

void    *ft_lstnew(int content);
int     ft_lstsize(t_list *lst);
void    ft_lstadd_front(t_list **lst, t_list *new);
void    ft_lstadd_back(t_list **lst, t_list *new);

void    sa(t_list *lst_a, int msg);
void    sb(t_list *lst_b, int msg);
void    ss(t_list *lst_a, t_list *lst_b);

void    ra(t_list *lst_a, int msg);
void    rb(t_list *lst_b, int msg);
void    rr(t_list *lst_a, t_list *lst_b);

void    rra(t_list **lst_a, int msg);
void    rrb(t_list **lst_b, int msg);
void    rrr(t_list **lst_a, t_list **lst_b);

void    pa(t_list **lst_a ,t_list **lst_b, int msg);
void    pb(t_list **lst_a ,t_list **lst_b, int msg);

void    sort_of_three(t_list **lst,int max, int min);
void	sort_of_five(t_list **lst_a, t_list **lst_b);
void    ft_print(t_list *lst_a, t_list *lst_b);


#endif