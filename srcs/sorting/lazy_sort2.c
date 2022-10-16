/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazy_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:46:13 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/17 00:10:16 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

int	max_two(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

static int min_two(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

void	do_instr(t_dlst *stack_a, t_dlst  *stack_b, t_r *p)
{
	if (p->ra && p->rb)
		rotate_rotate_count(stack_a, stack_b, min_two(p->ra, p->rb));
	else if (p->rra && p->rrb)
		rrotate_rotate_count(stack_a, stack_b, min_two(p->rra, p->rrb));
	rotate_count(stack_a, A, p->ra - p->rb);
	rotate_count(stack_b, B, p->rb - p->ra);
	rrotate_count(stack_a, A, p->rra - p->rrb);
	rrotate_count(stack_b, B, p->rrb - p->rra);
	push(stack_b, stack_a, B);
}