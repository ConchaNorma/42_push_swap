/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:32:20 by cnorma            #+#    #+#             */
/*   Updated: 2021/08/25 20:32:22 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lstn;

	lstn = NULL;
	lstn = (t_list *)malloc(sizeof(t_list));
	if (lstn == NULL)
		return (NULL);
	lstn->content = content;
	lstn->next = NULL;
	return (lstn);
}
