/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:33:57 by cnorma            #+#    #+#             */
/*   Updated: 2021/08/25 20:33:57 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	size_t	dstlen1;

	i = 0;
	j = ft_strlen(dst);
	dstlen1 = ft_strlen(dst);
	if (dst == NULL && src == NULL)
		return (0);
	if (size == 0)
		return (size + ft_strlen(src));
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	while ((j < (size - 1)) && src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dstlen1 + ft_strlen(src));
}
