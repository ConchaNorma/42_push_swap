/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:32:56 by cnorma            #+#    #+#             */
/*   Updated: 2021/08/25 20:32:56 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len-- > 0)
			dst1[len] = src1[len];
	}
	else
	{
		while (len > 0)
		{
			*dst1 = *src1;
			dst1++;
			src1++;
			len--;
		}
	}
	return (dst);
}
