/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:18 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/17 13:12:01 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void	rotate_rotate(t_dlst *stack_a, t_dlst *stack_b, int s)
{
	t_node	*tmp;

	tmp = dlst_removeback(stack_a);
	dlst_addfront(stack_a, tmp);
	tmp = dlst_removeback(stack_b);
	dlst_addfront(stack_b, tmp);
	if (s == AB)
		ft_printf("rr\n");
}

void	rotate_rotate_count(t_dlst *stack_a, t_dlst *stack_b, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		return ;
	while (i < n)
	{
		rotate_rotate(stack_a, stack_b, AB);
		i++;
	}
}

void	rotate_count(t_dlst *stack, int s, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		return ;
	while (i < n)
	{
		rotate(stack, s);
		i++;
	}
}

void	smart_rotate_partition(t_dlst *stack_a, t_dlst *stack_b, t_partition *p)
{

	if (p->np < 0)
		rrotate_count(stack_a, A, -p->np);
	else if (p->np > 1 && p->to_rr >= p->np - 1)
	{
		rotate_rotate_count(stack_a, stack_b, p->np - 1);
		p->to_rr = p->to_rr - (p->np - 1); 
	}
	else if (p->np > 1 && p->to_rr < p->np - 1)
	{
		rotate_rotate_count(stack_a, stack_b, p->to_rr);
		rotate_count(stack_a, A, p->np - 1 - p->to_rr);
		p->to_rr = 0;
	}
	if (p->group == Z && stack_b->last && !(only_z(stack_b, p)))
		(p->to_rr)++;
	else if (p->group == Y)
	{
		rotate_count(stack_b, B, p->to_rr);
		p->to_rr = 0;
	}
	push(stack_a, stack_b, A);
}

void	rotate(t_dlst *stack, int s)
{
	t_node	*tmp;

	tmp = dlst_removeback(stack);
	dlst_addfront(stack, tmp);
	if (s == A)
		ft_printf("ra\n");
	else if (s == B)
		ft_printf("rb\n");
}
/*last(top) go to fisrt(bottom)*/