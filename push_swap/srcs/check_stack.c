/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:47:22 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/06 19:40:37 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Check(t_Stack *a, int check)
{
	if (check < 0)
	{
		ft_putstr_fd("Error\n", 2);
		FreeStack(a);
		exit(1);
	}
	if (check == 1)
	{
		FreeStack(a);
		exit (0);
	}
}

void	CheckParam(int argc, char **str)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	i = 1;
	if (argc < 2)
		check = 1;
	else
	{
		while (str[i])
		{
			j = 0;
			while (str[i][j])
			{
				if ((str[i][j] == '-' || str[i][j] == '+'))
					j++;
				if ((str[i][j] < '0' || str[i][j] > '9'))
					check = -1;
				j++;
			}
			i++;
		}
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
