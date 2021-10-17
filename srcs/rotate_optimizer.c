/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_optimizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:58:29 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/12 00:11:09 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_optimizer_both1(t_Stack *src, t_Stack *dst, long long i)
{
	int		count_rev_dst;
	int		count_rrev_dst;
	int		count_rev_src;
	int		count_rrev_src;

	count_rev_dst = ft_rotate_counter_rev_num(dst, i);
	count_rrev_dst = ft_rotate_counter_rrev_num(dst, i);
	count_rev_src = ft_rotate_counter_rev(src, i);
	count_rrev_src = ft_rotate_counter_rrev(src, i);
	while (count_rev_dst && count_rev_src)
	{
		ft_stack_operate(src, dst, "rr");
		count_rev_dst--;
		count_rev_src--;
	}
	while (count_rev_src--)
		ft_stack_operate(src, NULL, "ra");
	while (count_rev_dst--)
		ft_stack_operate(dst, NULL, "rb");
}

void	ft_rotate_optimizer_both2(t_Stack *src, t_Stack *dst, long long i)
{
	int		count_rev_dst;
	int		count_rrev_dst;
	int		count_rev_src;
	int		count_rrev_src;

	count_rev_dst = ft_rotate_counter_rev_num(dst, i);
	count_rrev_dst = ft_rotate_counter_rrev_num(dst, i);
	count_rev_src = ft_rotate_counter_rev(src, i);
	count_rrev_src = ft_rotate_counter_rrev(src, i);
	while (count_rrev_dst && count_rrev_src)
	{
		ft_stack_operate(src, dst, "rrr");
		count_rrev_dst--;
		count_rrev_src--;
	}
	while (count_rrev_src--)
		ft_stack_operate(src, NULL, "rra");
	while (count_rrev_dst--)
		ft_stack_operate(dst, NULL, "rrb");
}

void	ft_rotate_optimizer_both3(t_Stack *src, t_Stack *dst, long long i)
{
	int		count_rev_dst;
	int		count_rrev_dst;
	int		count_rev_src;
	int		count_rrev_src;

	count_rev_dst = ft_rotate_counter_rev_num(dst, i);
	count_rrev_dst = ft_rotate_counter_rrev_num(dst, i);
	count_rev_src = ft_rotate_counter_rev(src, i);
	count_rrev_src = ft_rotate_counter_rrev(src, i);
	if (count_rev_src <= count_rrev_src)
	{
		while (count_rev_src--)
			ft_stack_operate(src, NULL, "ra");
	}
	else
	{
		while (count_rrev_src--)
			ft_stack_operate(src, NULL, "rra");
	}
}

void	ft_rotate_optimizer_both4(t_Stack *src, t_Stack *dst, long long i)
{
	int		count_rev_dst;
	int		count_rrev_dst;
	int		count_rev_src;
	int		count_rrev_src;

	count_rev_dst = ft_rotate_counter_rev_num(dst, i);
	count_rrev_dst = ft_rotate_counter_rrev_num(dst, i);
	count_rev_src = ft_rotate_counter_rev(src, i);
	count_rrev_src = ft_rotate_counter_rrev(src, i);
	if (count_rev_dst <= count_rrev_dst)
	{
		while (count_rev_dst--)
			ft_stack_operate(dst, NULL, "rb");
	}
	else
	{
		while (count_rrev_dst--)
			ft_stack_operate(dst, NULL, "rrb");
	}
}

void	ft_rotate_optimizer_both(t_Stack *src, t_Stack *dst, long long i)
{
	int		count_rev_dst;
	int		count_rrev_dst;
	int		count_rev_src;
	int		count_rrev_src;

	count_rev_dst = ft_rotate_counter_rev_num(dst, i);
	count_rrev_dst = ft_rotate_counter_rrev_num(dst, i);
	count_rev_src = ft_rotate_counter_rev(src, i);
	count_rrev_src = ft_rotate_counter_rrev(src, i);
	if (count_rev_dst <= count_rrev_dst && count_rev_src <= count_rrev_src)
		ft_rotate_optimizer_both1(src, dst, i);
	else if (count_rev_dst > count_rrev_dst && count_rev_src > count_rrev_src)
		ft_rotate_optimizer_both2(src, dst, i);
	else
	{
		ft_rotate_optimizer_both3(src, dst, i);
		ft_rotate_optimizer_both4(src, dst, i);
	}
}
