/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:55:35 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/06 08:51:15 by cnorma           ###   ########.fr       */
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

void	ft_stack_operate(t_Stack *a, t_Stack *b, char *index)
{
	if (!ft_strncmp(index, "sa", 3) || !ft_strncmp(index, "sb", 3))
		ft_stack_swap(a);
	else if (!ft_strncmp(index, "ss", 3))
	{
		ft_stack_swap(a);
		ft_stack_swap(b);
	}
	else if (!ft_strncmp(index, "ra", 3) || !ft_strncmp(index, "rb", 3))
		ft_stack_rev(a);
	else if (!ft_strncmp(index, "rr", 3))
	{
		ft_stack_rev(a);
		ft_stack_rev(b);
	}
	else if (!ft_strncmp(index, "rra", 4) || !ft_strncmp(index, "rrb", 4))
		ft_stack_rrev(a);
	else if (!ft_strncmp(index, "rrr", 3))
	{
		ft_stack_rrev(a);
		ft_stack_rrev(b);
	}
	else if (!ft_strncmp(index, "pa", 3) || !ft_strncmp(index, "pb", 3))
		ft_stack_push(a, b);
	write(1, index, ft_strlen(index));
	write(1, "\n", 1);
}
