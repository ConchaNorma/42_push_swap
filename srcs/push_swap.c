/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:01:42 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/12 20:05:59 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_Stack		*a;

	if (argc < 2)
		return (0);
	a = ft_create_stack();
	fillstackend(a, argc, argv);
	checkduplicates(a);
	checksorted(a);
	sortstack(a);
	return (0);
}
