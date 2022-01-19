/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:36:05 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/12 00:11:23 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_max_min_elem(t_Stack *src)
{
	t_lists	*tmp;

	tmp = src->head;
	if (tmp)
	{
		src->max = tmp->val;
		src->min = tmp->val;
		while (tmp)
		{
			if (src->min > tmp->val)
				src->min = tmp->val;
			if (src->max < tmp->val)
				src->max = tmp->val;
			tmp = tmp->next;
		}
	}
}

void	ft_stack_order_elem(t_Stack *src)
{
	t_lists	*tmp;
	t_lists	*tmp2;
	int		count;
	int		i;

	count = src->elem_count;
	i = 0;
	while (count--)
	{
		tmp = src->head;
		while (tmp->order)
			tmp = tmp->next;
		tmp2 = src->head;
		while (tmp2)
		{
			if (tmp2->order == 0)
				if (tmp->val > tmp2->val)
					tmp = tmp2;
			tmp2 = tmp2->next;
		}
		tmp->order = ++i;
	}
}
