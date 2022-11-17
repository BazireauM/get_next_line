/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:15:55 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/17 02:53:17 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stock = search_line(fd, stock);
	if (!stock)
		return (NULL);
	line = form_line(stock);
	stock = supp_line(stock);
	return (line);
}

char	*search_line(int fd, char *stock)
{
	char	*buffer;
	int		nb_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb_read = 1;
	while (!ft_strchr(stock, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	return (stock);
}

char	*form_line(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	if (!stock[0])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*supp_line(char	*stock)
{
	int		i;
	int		b;
	char	*tmp;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\0')
	{
		free(stock);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	b = 0;
	while (stock[i])
		tmp[b++] = stock[i++];
	tmp[b] = '\0';
	free(stock);
	return (tmp);
}
