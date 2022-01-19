/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:32:26 by cnorma            #+#    #+#             */
/*   Updated: 2021/08/25 20:32:28 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
