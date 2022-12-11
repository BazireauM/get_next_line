/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:15:21 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/17 02:53:19 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *stock, char *buffer)
{
	size_t	i;
	size_t	b;
	char	*final;

	if (!stock)
	{
		stock = (char *)malloc(1 * sizeof(char));
		stock[0] = '\0';
	}
	if (!stock || !buffer)
		return (NULL);
	final = malloc(sizeof(char) * ((ft_strlen(stock) + ft_strlen(buffer)) + 1));
	if (final == NULL)
		return (NULL);
	i = -1;
	b = 0;
	if (stock)
		while (stock[++i] != '\0')
			final[i] = stock[i];
	while (buffer[b] != '\0')
		final[i++] = buffer[b++];
	final[ft_strlen(stock) + ft_strlen(buffer)] = '\0';
	free(stock);
	return (final);
}
