/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:32:35 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/12 20:06:51 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_Stack *a, t_Stack *b)
{
	freestack(b);
	check_validity(a, -1);
}

void	ft_stack_operate_checker(t_Stack *a, t_Stack *b, char *index)
{
	if (!ft_strncmp(index, "sa", 3))
		ft_stack_swap(a);
	else if (!ft_strncmp(index, "sb", 3))
		ft_stack_swap(b);
	else if (!ft_strncmp(index, "ss", 3))
		ft_stack_swap_all(a, b);
	else if (!ft_strncmp(index, "ra", 3))
		ft_stack_rev(a);
	else if (!ft_strncmp(index, "rb", 3))
		ft_stack_rev(b);
	else if (!ft_strncmp(index, "rr", 3))
		ft_stack_rev_all(a, b);
	else if (!ft_strncmp(index, "rra", 4))
		ft_stack_rrev(a);
	else if (!ft_strncmp(index, "rrb", 4))
		ft_stack_rrev(b);
	else if (!ft_strncmp(index, "rrr", 3))
		ft_stack_rrev_all(a, b);
	else if (!ft_strncmp(index, "pa", 3))
		ft_stack_push(b, a);
	else if (!ft_strncmp(index, "pb", 3))
		ft_stack_push(a, b);
	else
		ft_error(a, b);
}

void	ft_read_action(t_Stack *a, t_Stack *b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_stack_operate_checker(a, b, line);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	sortchecker(t_Stack *a, t_Stack *b)
{
	t_lists	*tmp;
	int		check;

	check = 1;
	tmp = a->head;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			check = 0;
		tmp = tmp->next;
	}
	if (check == 1 && b->elem_count == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_Stack		*a;
	t_Stack		*b;

	if (argc < 2)
		return (0);
	a = ft_create_stack();
	fillstackend(a, argc, argv);
	checkduplicates(a);
	b = ft_create_stack();
	ft_read_action(a, b);
	sortchecker(a, b);
	freestack(b);
	freestack(a);
	return (0);
}
