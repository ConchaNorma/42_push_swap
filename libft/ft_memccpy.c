/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:32:32 by cnorma            #+#    #+#             */
/*   Updated: 2021/08/25 20:32:33 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (n > 0)
	{
		*dst1 = *src1;
		if (*src1 == (unsigned char)c)
			return (++dst1);
		dst1++;
		src1++;
		n--;
	}
	return (NULL);
}
