/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:40:24 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 15:17:39 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	static int	len;
	char		*tmp;

	if (!buffer)
	{
		buffer = first_call(&len, buffer, tmp, fd);
		if (buffer == NULL)
			return (NULL);
	}
	while (line_in_buffer(buffer, len) != 1)
	{
		if (line_in_buffer(buffer, len) == 1)
		{
			tmp = form_line(buffer, len, tmp);
			return (tmp);
		}
		else
		{
			buffer = append_buffer(buffer, len, tmp, fd);
			if (buffer == NULL)
				return (NULL);
		}
	}
	return (NULL);
}

char	*first_call(int *len, char *buffer, char *tmp, int fd)
{
	int	i;
	int	a;

	*len = BUFFER_SIZE;
	tmp = ft_calloc(1, BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	a = read(fd, tmp, BUFFER_SIZE);
	buffer = malloc(sizeof(char) * a);
	if (!buffer)
	{
		free(tmp);
		return (NULL);
	}
	*len = a;
	i = 0;
	while (i < a)
	{
		buffer[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (buffer);
}

int	line_in_buffer(char *buffer, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*form_line(char *buffer, int len, char *tmp)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (buffer[i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	while (b < i)
	{
		tmp[b] = buffer[b];
		b++;
	}
	tmp[b] = '\0';
	if (buffer_reset_one_line(buffer, len, i) == 1)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

int	buffer_reset_one_line(char *buffer, int len, int i)
{
	char	*tmp;
	int		b;

	tmp = malloc(sizeof(char) * (len - i));
	if (!tmp)
		return (1);
	b = 0;
	while (b < len - i)
	{
		tmp[b] = buffer[len + b];
		b++;
	}
	free(buffer);
	buffer = malloc(sizeof(char) * b);
	if (!buffer)
	{
		return (1);
		free(tmp);
	}
	len = b;
	b = 0;
	while (b < len)
	{
		buffer[b] = tmp[b];
		b++;
	}
	free(tmp);
	return (0);
}
