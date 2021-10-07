/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:47:22 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/07 21:15:48 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Check(t_Stack *a, int check)
{
	if (check < 0)
	{
		ft_putstr_fd("Error\n", 2);
		if (a)
			FreeStack(a);
		exit(1);
	}
	if (check == 1)
	{
		if (a)
			FreeStack(a);
		exit (0);
	}
}

void	CheckParam(char *str)
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
	Check(NULL, check);
}

void	CheckDuplicates(t_Stack *src)
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
	Check(src, check);
}

void	CheckSorted(t_Stack *src)
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
	Check(src, check);
}

int	ft_atoi_ps(const char *str)
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
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
	return (num * sign);
}
