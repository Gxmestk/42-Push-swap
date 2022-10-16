/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazy_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:46:13 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/16 20:20:04 by tkhemniw         ###   ########.fr       */
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

	//ft_printf("p->ra = %d p->rb = %d p->rra = %d p->rrb = %d\n",p->ra,p->rb,p->rra,p->rrb);
	//ft_printf("-----------TOP------------\n");
	//if (stack_b->size)
		//dlst_print(stack_b, B);
	if (p->ra && p->rb)
		rotate_rotate_count(stack_a, stack_b, min_two(p->ra, p->rb));
	else if (p->rra && p->rrb)
		rrotate_rotate_count(stack_a, stack_b, min_two(p->rra, p->rrb));
	//ft_printf("-----------MID------------\n");
	//if (stack_b->size)
		//dlst_print(stack_b, B);
	rotate_count(stack_a, A, p->ra - p->rb);
	rotate_count(stack_b, B, p->rb - p->ra);
	rrotate_count(stack_a, A, p->rra - p->rrb);
	rrotate_count(stack_b, B, p->rrb - p->rra);
	//dlst_print(stack_a, A);
	//dlst_print(stack_b, B);
	//ft_printf("-------------------\n");
	//ft_printf("-----------BOT------------\n");
	//if (stack_b->size)
		//dlst_print(stack_b, B);
	push(stack_b, stack_a, B);
}