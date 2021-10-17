/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:55:35 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/12 00:10:55 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_swap(t_Stack *a)
{
	t_lists	*tmp1;
	t_lists	*tmp2;

	if (a->head && a->head->next)
	{
		tmp1 = a->head;
		tmp2 = a->head->next;
		tmp1->next = tmp2->next;
		tmp1->prev = tmp2;
		tmp2->next->prev = tmp1;
		tmp2->prev = NULL;
		tmp2->next = a->head;
		a->head = tmp2;
	}
}

void	ft_stack_rev(t_Stack *a)
{
	t_lists	*tmp1;
	t_lists	*tmp2;

	if (a->head && a->head->next)
	{
		tmp1 = a->head;
		tmp2 = a->head->next;
		tmp1->next = NULL;
		tmp1->prev = a->tail;
		a->tail->next = tmp1;
		a->tail = tmp1;
		tmp2->prev = NULL;
		a->head = tmp2;
	}
}

void	ft_stack_rrev(t_Stack *a)
{
	t_lists	*tmp1;
	t_lists	*tmp2;

	if (a->tail && a->tail->prev)
	{
		tmp1 = a->tail;
		tmp2 = a->tail->prev;
		tmp1->prev = NULL;
		tmp1->next = a->head;
		a->head->prev = tmp1;
		a->head = tmp1;
		tmp2->next = NULL;
		a->tail = tmp2;
	}
}

void	ft_stack_push(t_Stack *src, t_Stack *dst)
{
	t_lists	*tmp1;
	t_lists	*tmp2;

	if (src->head)
	{
		tmp1 = src->head;
		tmp2 = src->head->next;
		tmp1->next = dst->head;
		if (dst->head)
			dst->head->prev = tmp1;
		dst->head = tmp1;
		if (!dst->tail)
			dst->tail = dst->head;
		if (tmp2)
			tmp2->prev = NULL;
		src->head = tmp2;
		src->elem_count--;
		dst->elem_count++;
	}
	ft_stack_max_min_elem(src);
	ft_stack_max_min_elem(dst);
}
