/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:47:22 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/12 19:36:54 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_validity(t_Stack *a, int check)
{
	if (check < 0)
	{
		ft_putstr_fd("Error\n", 2);
		freestack(a);
		exit(1);
	}
	if (check == 1)
	{
		freestack(a);
		exit (0);
	}
}

void	checkparam(char *str)
{
	int	j;
	int	check;

	check = 0;
	j = 0;
	while (str[j])
	{
		if ((str[j] == '-' || str[j] == '+'))
			j++;
		if ((str[j] < '0' || str[j] > '9'))
			check = -1;
		j++;
	}
	check_validity(NULL, check);
}

void	checkduplicates(t_Stack *src)
{
	t_lists	*tmp;
	t_lists	*tmp2;
	int		check;

	check = 0;
	tmp = src->head;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->val == tmp2->val)
				check = -1;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	check_validity(src, check);
}

void	checksorted(t_Stack *src)
{
	t_lists	*tmp;
	int		check;

	check = 1;
	tmp = src->head;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			check = 0;
		tmp = tmp->next;
	}
	check_validity(src, check);
}

int	ft_atoi_ps(t_Stack *a, const char *str)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1 * sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + ((int)*str - '0');
		str++;
		if (((num * sign) > INT_MAX) || ((num * sign) < INT_MIN))
			check_validity(a, -1);
	}
	return (num * sign);
}
