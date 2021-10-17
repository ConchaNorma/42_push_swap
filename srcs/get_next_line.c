/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:11:15 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/13 21:30:36 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_line(int fd, char **line)
{
	int		rd;
	int		i;
	char	ch;
	char	*buffer;

	i = 0;
	buffer = malloc(100);
	*line = buffer;
	rd = read(fd, &ch, 1);
	while (rd > 0 && ch != '\n')
	{
		buffer[i++] = ch;
		rd = read(fd, &ch, 1);
	}
	buffer[i] = '\0';
	return (rd);
}
