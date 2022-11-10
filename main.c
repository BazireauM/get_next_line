/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:41:02 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 15:17:48 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *test;

	fd = open("test",O_RDONLY);
	test = get_next_line(fd);
	printf("%s\n", test);
	return (0);
}
