/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:36:05 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/07 21:51:43 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Stack	*ft_create_stack(void)
{
	t_Stack	*tmp;

	tmp = (t_Stack *)malloc(sizeof(t_Stack));
	if (!tmp)
		exit (1);
	tmp->head = NULL;
	tmp->tail = NULL;
	tmp->elem_count = 0;
	tmp->max = 0;
	tmp->min = 0;
	return (tmp);
}

t_lists	*ft_listnew(void)
{
	t_lists	*lst;

	lst = NULL;
	lst = (t_lists *)malloc(sizeof(t_lists));
	if (lst == NULL)
		exit (1);
	return (lst);
}

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

void	FillStackEnd(t_Stack *a, int argc, char **str)
{
	t_lists	*tmp;
	int		i;
	int		j;
	char	**ss;

	i = 1;
	while (i < argc)
	{
		ss = ft_split(str[i], ' ');
		j = 0;
		while (ss[j])
		{
			CheckParam(ss[j]);
			tmp = ft_listnew();
			tmp->val = ft_atoi_ps(ss[j]);
			tmp->order = 0;
			tmp->stepnum = 0;
			tmp->prev = a->tail;
			tmp->next = NULL;
			if (a->tail)
				a->tail->next = tmp;
			a->tail = tmp;
			if (!a->head)
				a->head = a->tail;
			a->elem_count++;
			j++;
		}
		j = 0;
		while (ss[j])
			free(ss[j++]);
		free(ss);
		i++;
	}
	ft_stack_max_min_elem(a);
	ft_stack_order_elem(a);
}
