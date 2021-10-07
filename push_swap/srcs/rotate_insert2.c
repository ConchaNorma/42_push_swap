/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_insert2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:55:23 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/06 08:51:56 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_counter_rrev_sup1(t_Stack *src, long long i)
{
	int		count_rrev;
	t_lists	*tmp;

	count_rrev = 0;
	tmp = src->tail;
	count_rrev++;
	while (i != tmp->val)
	{
		count_rrev++;
		tmp = tmp->prev;
	}
	return (count_rrev);
}

int	ft_rotate_counter_rrev_sup2(t_Stack *src, long long i)
{
	int		count_rrev;
	t_lists	*tmp;

	count_rrev = 0;
	tmp = src->tail;
	while (tmp->val != src->max)
	{
		if (i > tmp->val)
		{
			count_rrev++;
			tmp = tmp->prev;
		}
	}
	while (i < tmp->val)
	{
		count_rrev++;
		if (!tmp->prev)
			break ;
		tmp = tmp->prev;
	}
	return (count_rrev);
}

int	ft_rotate_counter_rrev(t_Stack *src, long long i)
{
	int		count_rrev;
	t_lists	*tmp;

	count_rrev = 0;
	tmp = src->tail;
	if (i < src->head->val && i > src->tail->val)
		return (count_rrev);
	if (i == src->min)
		count_rrev = ft_rotate_counter_rrev_sup1(src, i);
	else if (i < src->tail->val && i > src->min)
	{
		while (i < tmp->val)
		{
			count_rrev++;
			tmp = tmp->prev;
		}
	}
	else
		count_rrev = ft_rotate_counter_rrev_sup2(src, i);
	return (count_rrev);
}

void	ft_rotate_optimizer(t_Stack *src, long long i)
{
	int		count_rev;
	int		count_rrev;

	count_rev = ft_rotate_counter_rev(src, i);
	count_rrev = ft_rotate_counter_rrev(src, i);
	if (count_rev <= count_rrev)
	{
		while (count_rev--)
			ft_stack_operate(src, NULL, "ra");
	}
	else
	{
		while (count_rrev--)
			ft_stack_operate(src, NULL, "rra");
	}
}
