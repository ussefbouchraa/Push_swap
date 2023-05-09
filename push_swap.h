/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:49:37 by ybouchra          #+#    #+#             */
/*   Updated: 2023/05/09 13:04:25 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int     ft_isdigit(char *s);
int	    ft_atoi(char *s);
char	**ft_split(const char *str, char c);
size_t  ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strdup(const char *s);
int     nbr_args(char **av);


#endif