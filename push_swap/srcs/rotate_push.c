/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:56:58 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/06 08:52:27 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_counter_rev_num(t_Stack *src, long long i)
{
	int		count_rev;
	t_lists	*tmp;

	count_rev = 0;
	tmp = src->head;
	while (tmp->val != i)
	{
		count_rev++;
		tmp = tmp->next;
	}
	return (count_rev);
}

int	ft_rotate_counter_rrev_num(t_Stack *src, long long i)
{
	int		count_rrev;
	t_lists	*tmp;

	count_rrev = 1;
	tmp = src->tail;
	while (tmp->val != i)
	{
		count_rrev++;
		tmp = tmp->prev;
	}
	return (count_rrev);
}

void	ft_rotate_optimizer_num_a(t_Stack *src, long long i)
{
	int		count_rev;
	int		count_rrev;

	count_rev = ft_rotate_counter_rev_num(src, i);
	count_rrev = ft_rotate_counter_rrev_num(src, i);
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
