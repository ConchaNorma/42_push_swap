/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:36:05 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/12 20:06:39 by cnorma           ###   ########.fr       */
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

void	listaddtostacktail(t_Stack *a, char **str)
{
	t_lists	*tmp;

	tmp = ft_listnew();
	tmp->val = ft_atoi_ps(a, *str);
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
}

void	fillstackend(t_Stack *a, int argc, char **str)
{
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
			checkparam(ss[j]);
			listaddtostacktail(a, &ss[j]);
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

void	freestack(t_Stack *src)
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
