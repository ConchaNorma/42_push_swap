/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:36:36 by cnorma            #+#    #+#             */
/*   Updated: 2021/08/25 20:36:37 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (s == NULL || start >= ft_strlen(s) || len <= 0)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	subs = (char *)ft_calloc((len + 1), sizeof(char));
	if (subs == NULL)
		return (NULL);
	while (s[start] && (i < len))
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	return (subs);
}
