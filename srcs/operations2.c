/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:55:35 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/12 19:38:28 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_swap_all(t_Stack *a, t_Stack *b)
{
	ft_stack_swap(a);
	ft_stack_swap(b);
}

void	ft_stack_rev_all(t_Stack *a, t_Stack *b)
{
	ft_stack_rev(a);
	ft_stack_rev(b);
}

void	ft_stack_rrev_all(t_Stack *a, t_Stack *b)
{
	ft_stack_rrev(a);
	ft_stack_rrev(b);
}

void	ft_stack_operate(t_Stack *a, t_Stack *b, char *index)
{
	if (!ft_strncmp(index, "sa", 3) || !ft_strncmp(index, "sb", 3))
		ft_stack_swap(a);
	else if (!ft_strncmp(index, "ss", 3))
		ft_stack_swap_all(a, b);
	else if (!ft_strncmp(index, "ra", 3) || !ft_strncmp(index, "rb", 3))
		ft_stack_rev(a);
	else if (!ft_strncmp(index, "rr", 3))
		ft_stack_rev_all(a, b);
	else if (!ft_strncmp(index, "rra", 4) || !ft_strncmp(index, "rrb", 4))
		ft_stack_rrev(a);
	else if (!ft_strncmp(index, "rrr", 3))
		ft_stack_rrev_all(a, b);
	else if (!ft_strncmp(index, "pa", 3) || !ft_strncmp(index, "pb", 3))
		ft_stack_push(a, b);
	else
	{
		check_validity(b, -1);
		check_validity(a, -1);
	}
	write(1, index, ft_strlen(index));
	write(1, "\n", 1);
}
