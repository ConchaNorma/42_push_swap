/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_insert1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:53:42 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/12 00:11:03 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_counter_rev_sup1(t_Stack *src, long long i)
{
	int		count_rev;
	t_lists	*tmp;

	count_rev = 0;
	tmp = src->head;
	while (i != tmp->val)
	{
		count_rev++;
		tmp = tmp->next;
	}
	return (count_rev);
}

int	ft_rotate_counter_rev_sup2(t_Stack *src, long long i)
{
	int		count_rev;
	t_lists	*tmp;

	count_rev = 0;
	tmp = src->head;
	while (tmp->val != src->min)
	{
		if (i < tmp->val)
		{
			count_rev++;
			tmp = tmp->next;
		}
	}
	while (i > tmp->val)
	{
		count_rev++;
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (count_rev);
}

int	ft_rotate_counter_rev(t_Stack *src, long long i)
{
	int		count_rev;
	t_lists	*tmp;

	count_rev = 0;
	tmp = src->head;
	if (i < src->head->val && i > src->tail->val)
		return (count_rev);
	if (i == src->min)
		count_rev = ft_rotate_counter_rev_sup1(src, i);
	else if (i > src->head->val && i < src->max)
	{
		while (i > tmp->val)
		{
			count_rev++;
			tmp = tmp->next;
		}
	}
	else
		count_rev = ft_rotate_counter_rev_sup2(src, i);
	return (count_rev);
}
