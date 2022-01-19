/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:44:07 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/12 19:27:44 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int i, int j)
{
	if (i <= j)
		return (i);
	else
		return (j);
}

void	ft_stepnum(t_Stack *src, t_Stack *dst)
{
	t_lists		*tmp;
	int			count_rev_src;
	int			count_rrev_src;
	int			count_rev_dst;
	int			count_rrev_dst;

	tmp = src->head;
	while (tmp)
	{
		count_rev_src = ft_rotate_counter_rev_num(src, tmp->val);
		count_rrev_src = ft_rotate_counter_rrev_num(src, tmp->val);
		count_rev_dst = ft_rotate_counter_rev(dst, tmp->val);
		count_rrev_dst = ft_rotate_counter_rrev(dst, tmp->val);
		tmp->stepnum = ft_min(count_rev_src, count_rrev_src)
			+ ft_min(count_rev_dst, count_rrev_dst);
		tmp = tmp->next;
	}
}

int	ft_mid_val(t_Stack *src)
{
	t_lists	*p;
	int		mid_val;
	int		i;

	i = src->elem_count;
	p = src->head;
	while (p)
	{
		if (p->order == (src->elem_count / 2) + 1)
			mid_val = p->val;
		p = p->next;
	}
	return (mid_val);
}

void	pushtobwithmid(t_Stack *src, t_Stack *dst)
{
	t_lists		*p;
	long long	mid_val;
	int			i;

	i = src->elem_count;
	mid_val = ft_mid_val(src);
	while (i > 3)
	{
		p = src->head;
		if (p->val != src->max && p->val != src->min && p->val != mid_val)
		{
			if (p->val < mid_val)
				ft_stack_operate(src, dst, "pb");
			else if (p->val > mid_val)
			{
				ft_stack_operate(src, dst, "pb");
				ft_stack_operate(dst, NULL, "rb");
			}
		}
		else
			ft_stack_operate(src, NULL, "ra");
		i = src->elem_count;
	}
}

int	ft_min_stepnum(t_Stack *dst)
{
	t_lists		*p;
	long long	min_stepnum_val;
	int			min_stepnum;

	p = dst->head;
	min_stepnum = p->stepnum;
	min_stepnum_val = p->val;
	while (p)
	{
		if (p->stepnum < min_stepnum)
		{
			min_stepnum = p->stepnum;
			min_stepnum_val = p->val;
		}
		p = p->next;
	}
	return (min_stepnum_val);
}
