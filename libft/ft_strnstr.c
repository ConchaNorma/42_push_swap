/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:34:32 by cnorma            #+#    #+#             */
/*   Updated: 2021/08/25 20:36:23 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i++])
		;
	return (--i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	while (i < len)
	{
		j = 0;
		while (little[j] == big[i] && j < ft_strlen(little))
		{
			if ((j == 0 && (i + ft_strlen(little)) > len)
				|| (ft_strlen(little) > ft_strlen(big)))
				return (NULL);
			j++;
			i++;
		}
		if (j == ft_strlen(little))
			return ((char *)&big[i - ft_strlen(little)]);
		else
			i -= (j - 1);
	}
	return (NULL);
}
