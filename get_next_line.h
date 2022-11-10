/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:40:49 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 15:17:50 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*first_call(int *len, char *buffer, char *tmp, int fd);
int		line_in_buffer(char *buffer, int len);
void	*ft_calloc(size_t count, size_t size);
char	*form_line(char *buffer, int len, char *tmp);
int		buffer_reset_one_line(char *buffer, int len, int i);
char	*append_buffer(char *buffer, int len, char *tmp, int fd);

#endif
