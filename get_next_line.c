/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:40:24 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/07 14:42:09 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char **buffer;
	int a;
	int b;
	if (!buffer)
	{
		buffer = malloc(sizeof(char *) * 1);
		buffer[0] = NULL;
	}
	char		*tmp;
	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	read(fd, tmp, BUFFER_SIZE);
	a = sizeof_char_char(buffer);
	b = n_line(BUFFER_SIZE, tmp);
	tmp2 = mallloc(sizeof(char *) * (a + b + 1));
	tmp2[a + b] = NULL;
	free(tmp);
	return (0);
}

int n_line (int buffer_size, char *tmp)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (i < buffer_size)
	{
		if (tmp[i] == '\0')
			b++;
		i++;
	}
	return (b);
}

int	sizeof_char_char(char **buffer)
{
	int i;

	i = 0;
	while (buffer[i] != NULL)
		i++;
	i++;
	return (i);
}
