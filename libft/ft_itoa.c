/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:32:00 by cnorma            #+#    #+#             */
/*   Updated: 2021/08/25 20:32:01 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_size(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_str_size(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0 && n > -2147483648)
	{
		str[0] = '-';
		n = -n;
	}
	str[len--] = '\0';
	while (n > 0)
	{
		str[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

static int	ft_str_size(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		if (n < 0 && len == 0)
			len++;
		n = n / 10;
		len++;
	}
	return (len);
}
