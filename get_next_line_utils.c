/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:40:53 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/11 14:22:30 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*test;
	char	*null;
	size_t	i;

	test = malloc (count * size);
	if (!test)
		return (NULL);
	null = (char *) test;
	i = 0;
	while (i < count * size)
	{
		null[i] = '\0';
		i++;
	}
	return (test);
}

char	*append_buffer(char *buffer, int *len, char *tmp, int fd)
{
	int		a;
	int		i;
	char	*tmp2;

	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	a = read(fd, tmp, BUFFER_SIZE);
	tmp2 = malloc(sizeof(char) * *len);
	if (!tmp2)
	{
		free(tmp);
		return (NULL);
	}
	i = 0;
	while (i < *len)
	{
		tmp2[i] = buffer[i];
		i++;
	}
	free(buffer);
	*len = *len + a;
	buffer = malloc(sizeof(char) * *len);
	if (!buffer)
	{
		free(tmp2);
		free(tmp);
		return (NULL);
	}
	i = 0;
	while (i < *len - a)
	{
		buffer[i] = tmp2[i];
		i++;
	}
	a = 0;
	while (i < *len)
	{
		buffer[i] = tmp[a];
		i++;
		a++;
	}
	free(tmp);
	free(tmp2);
	return (buffer);
}
