/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:52:54 by cnorma            #+#    #+#             */
/*   Updated: 2021/10/13 21:47:38 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_lists
{
	long long		val;
	int				order;
	int				stepnum;
	struct s_lists	*next;
	struct s_lists	*prev;
}			t_lists;

typedef struct s_Stack
{
	t_lists	*head;
	t_lists	*tail;
	int		max;
	int		min;
	int		elem_count;
}			t_Stack;

t_Stack	*ft_create_stack(void);
t_lists	*ft_listnew(void);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi_ps(t_Stack *src, const char *str);
void	ft_stack_max_min_elem(t_Stack *src);
void	ft_stack_order_elem(t_Stack *src);
void	fillstackend(t_Stack *a, int argc, char **str );
void	listaddtostacktail(t_Stack *a, char **str);
void	freestack(t_Stack *src);
void	check_validity(t_Stack *a, int check);
void	checkparam(char *str);
void	checkduplicates(t_Stack *src);
void	checksorted(t_Stack *src);
void	ft_stack_swap(t_Stack *a);
void	ft_stack_rev(t_Stack *a);
void	ft_stack_rrev(t_Stack *a);
void	ft_stack_swap_all(t_Stack *a, t_Stack *b);
void	ft_stack_push(t_Stack *src, t_Stack *dst);
void	ft_stack_rev_all(t_Stack *a, t_Stack *b);
void	ft_stack_rrev_all(t_Stack *a, t_Stack *b);
void	ft_stack_operate(t_Stack *a, t_Stack *b, char *index);
int		ft_rotate_counter_rev_sup1(t_Stack *src, long long i);
int		ft_rotate_counter_rev_sup2(t_Stack *src, long long i);
int		ft_rotate_counter_rev(t_Stack *src, long long i);
int		ft_rotate_counter_rrev_sup1(t_Stack *src, long long i);
int		ft_rotate_counter_rrev_sup2(t_Stack *src, long long i);
int		ft_rotate_counter_rrev(t_Stack *src, long long i);
void	ft_rotate_optimizer(t_Stack *src, long long i);
int		ft_rotate_counter_rev_num(t_Stack *src, long long i);
int		ft_rotate_counter_rrev_num(t_Stack *src, long long i);
void	ft_rotate_optimizer_num_a(t_Stack *src, long long i);
void	ft_stack_sort_3(t_Stack *src);
void	ft_stack_sort_small(t_Stack *src, t_Stack *dst);
int		ft_min(int i, int j);
void	ft_stepnum(t_Stack *src, t_Stack *dst);
int		ft_mid_val(t_Stack *src);
void	pushtobwithmid(t_Stack *src, t_Stack *dst);
void	ft_rotate_optimizer_both1(t_Stack *src, t_Stack *dst, long long i);
void	ft_rotate_optimizer_both2(t_Stack *src, t_Stack *dst, long long i);
void	ft_rotate_optimizer_both3(t_Stack *src, t_Stack *dst, long long i);
void	ft_rotate_optimizer_both4(t_Stack *src, t_Stack *dst, long long i);
void	ft_rotate_optimizer_both(t_Stack *src, t_Stack *dst, long long i);
int		ft_min_stepnum(t_Stack *dst);
void	ft_stack_sort_big(t_Stack *src, t_Stack *dst);
void	sortstack(t_Stack *a);
int		get_next_line(int fd, char **line);
void	ft_error(t_Stack *a, t_Stack *b);
void	ft_stack_operate_checker(t_Stack *a, t_Stack *b, char *index);
void	ft_read_action(t_Stack *a, t_Stack *b);
void	sortchecker(t_Stack *a, t_Stack *b);

#endif
