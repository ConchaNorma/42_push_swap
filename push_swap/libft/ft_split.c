/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:33:31 by cnorma            #+#    #+#             */
/*   Updated: 2021/08/25 20:33:33 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_malloc(char **ss)
{
	unsigned int	i;

	i = 0;
	while (ss[i])
		free(ss[i++]);
	free(ss);
	return (NULL);
}

static unsigned int	ft_str_num(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count_str;

	i = 0;
	if (!s[0])
		return (0);
	count_str = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count_str++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count_str);
}

static char	**ft_word(char const *s, char c, char **ss, unsigned int str_num)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (*s != '\0' && j < str_num)
	{
		while (*s == c && *s)
			s++;
		i = 0;
		while (s[i] != c)
			i++;
		ss[j] = ft_substr((s), 0, i);
		if (ss[j++] == NULL)
			return (ft_free_malloc(ss));
		s += i;
	}
	ss[j] = NULL;
	return (ss);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	str_num;
	char			**ss;

	if (s == NULL)
		return (NULL);
	str_num = ft_str_num(s, c);
	ss = malloc(sizeof(char *) * (str_num + 1));
	if (ss == NULL)
		return (NULL);
	return (ft_word(s, c, ss, str_num));
}
