/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:49:37 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/09 18:24:26 by ybouchra         ###   ########.fr       */
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

int     ft_isdigit(char *s);
long	ft_atoi(char *s);
char	**ft_split(const char *str, char c);
size_t  ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strdup(const char *s);
void    ft_clear(char **arr);
int     nbr_args(char **av);

#endif