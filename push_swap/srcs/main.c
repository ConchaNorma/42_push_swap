/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:01:42 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/07 21:49:54 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_Stack		*a;

	if (argc < 2)
		return (0);
	a = ft_create_stack();
	FillStackEnd(a, argc, argv);
	CheckDuplicates(a);
	CheckSorted(a);
	SortStack(a);
	return (0);
}
