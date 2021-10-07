/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:39:02 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/06 20:02:15 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_sort_3(t_Stack *src)
{
	if (src->elem_count == 3)
	{
		if (((src->head->val == src->min) && (src->tail->val != src->max))
			|| ((src->head->val == src->max) && (src->tail->val == src->min))
			|| ((src->head->next->val == src->min)
				&& (src->tail->val == src->max)))
			ft_stack_operate(src, NULL, "sa");
		if (src->head->val == src->max && src->tail->val != src->min)
			ft_stack_operate(src, NULL, "ra");
		else if (src->tail->val == src->min && src->head->val != src->max)
			ft_stack_operate(src, NULL, "rra");
	}
	else if (src->elem_count == 2 && (src->head->val > src->tail->val))
		ft_stack_operate(src, NULL, "ra");
}

void	ft_stack_sort_small(t_Stack *src, t_Stack *dst)
{
	while (src->elem_count > 3)
		ft_stack_operate(src, dst, "pb");
	ft_stack_sort_3(src);
	while (dst->head)
	{
		if (dst->head->val > src->max || dst->head->val < src->min)
		{
			ft_rotate_optimizer(src, src->min);
			ft_stack_operate(dst, src, "pa");
		}
		else
		{
			if ((dst->head->val > src->min) && (dst->head->val < src->max))
				ft_rotate_optimizer(src, dst->head->val);
			ft_stack_operate(dst, src, "pa");
		}
	}
	if (src->head->val != src->min)
		ft_rotate_optimizer(src, src->min);
}

void	ft_stack_sort_big(t_Stack *src, t_Stack *dst)
{
	long long	min_stepnum_val;

	PushToBwithMid(src, dst);
	ft_stack_sort_3(src);
	while (dst->head)
	{
		ft_stepnum(dst, src);
		min_stepnum_val = ft_min_stepnum(dst);
		ft_rotate_optimizer_both(src, dst, min_stepnum_val);
		ft_stack_operate(dst, src, "pa");
	}
	if (src->head->val != src->min)
		ft_rotate_optimizer_num_a(src, src->min);
}

void	SortStack(t_Stack *a)
{
	t_Stack	*b;

	if (a->elem_count > 1 && a->elem_count <= 3)
		ft_stack_sort_3(a);
	if (a->elem_count > 3)
	{
		b = ft_create_stack();
		if (a->elem_count <= 6)
			ft_stack_sort_small(a, b);
		else if (a->elem_count > 6)
			ft_stack_sort_big(a, b);
		FreeStack(b);
	}
	FreeStack(a);
}

void	FreeStack(t_Stack *src)
{
	t_lists	*tmp;

	tmp = NULL;
	if (src)
	{
		while (src->head)
		{
			if (src->head->next)
				tmp = src->head->next;
			free(src->head);
			src->head = NULL;
			src->head = tmp;
			tmp = NULL;
		}
		free(src);
		src = NULL;
	}
}
