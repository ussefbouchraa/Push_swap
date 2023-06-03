/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:49:37 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/03 00:03:15 by ybouchra         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif


typedef struct s_stack1
{
    int content;
    int pos;
    struct s_stack1 *next;
}   t_list;

char	**ft_split(const char *str, char c);
size_t  ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
int     ft_strcmp(char *s1, char *s2);
long	ft_atoi(char *s);
char	*get_next_line(int fd);

int     ft_isdigit(char *s);
int     ft_isspace(char *s);
int     ft_issorted(t_list *lst);
int     ft_max(t_list *lst);
int     ft_min(t_list *lst);

void    ft_clear(char **arr);
void    free_lnkedlist(t_list **lst);
int     nbr_args(char **av);
int     ft_pos_max(t_list *lst);

void    *ft_lstnew(int content);
int     ft_lstsize(t_list *lst);
void    ft_lstadd_front(t_list **lst, t_list *new);
void    ft_lstadd_back(t_list **lst, t_list *new);

void    sa(t_list *lst_a, int msg);
void    ra(t_list **lst, int msg);

void    ss(t_list *lst_a, t_list *lst_b, int msg);
void    rr(t_list **lst_a, t_list **lst_b, int msg);

void    rra(t_list **lst_a, int msg);
void    rrr(t_list **lst_a, t_list **lst_b, int msg);

void    pa(t_list **lst_a ,t_list **lst_b, int msg);

void    sort_of_three(t_list **lst,int max, int min);
void	sort_of_four(t_list **lst_a, t_list **lst_b, int min);
void	sort_of_five(t_list **lst_a, t_list **lst_b, int min);
void	sort_all(t_list **lst_a, t_list **lst_b, int size);
void	ft_check_b(t_list **lst_b, t_list **lst_a,int chnk, int demi_chnk);
void    ft_pa(t_list **lst_a, t_list **lst_b);

void    check_args(char **args);
char    **split_args(char **av, int words);
int     ft_valid_size(char *arg);

void    ft_print(t_list *lst_a, t_list *lst_b);

#endif