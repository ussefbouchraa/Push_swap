/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:32:23 by ybouchra          #+#    #+#             */
/*   Updated: 2023/06/03 23:10:03 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*readall(char *saved, int fd)
{
	int		dr;
	char	*buffer;

	dr = 1;
			buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (dr != 0 && !(ft_strchr(saved, '\n')))
	{
		dr = read(fd, buffer, BUFFER_SIZE);
		if (dr == -1)
		{
			free(buffer);
			buffer = NULL;
			return (free(saved), saved = NULL, NULL);
		}
		if (dr == 0)
			break ;
		buffer[dr] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	free(buffer);
	buffer = NULL;
	return (saved);
}

char	*getln(char *saved)
{
	char	*line;
	int		i;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free(saved), saved = NULL, NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*restln(char *saved)
{
	char	*rest;
	int		i;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	if (saved[i] == '\0')
		return (free(saved), saved = NULL, NULL);
	rest = ft_strdup(saved + i);
	free (saved);
	saved = NULL;
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	saved = readall(saved, fd);
	if (!saved)
		return (NULL);
	line = getln(saved);
	if (!line)
		return (NULL);
	saved = restln(saved);
	return (line);
}
