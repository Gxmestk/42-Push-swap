/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:15:19 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/16 10:03:41 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  0 - 31, 32 - 63, 64 - 95//96
  0 - 31, 32 - 63, 64 - 96//97
  0 - 31, 32 - 63+1, 64+1 - 97//98
  0 - 32, 33 - 65, 66 - 98//99
  0 - 32, 33 - 65, 66 - 99//100*/
#include "sorting.h"

static void log_base_three_pivot(int *sort, int *pivot_val, int nc)
{
	pivot_val[0] = sort[nc / 3];
	pivot_val[1] = sort[nc / 3 * 2];
	if (nc % 3 == 2)
		pivot_val[1] = sort[nc / 3 * 2 + 1];
	pivot_val[2] = sort[nc - 1];
}

static void	divided_groups(t_dlst *stack_a, t_partition *p)
{
	t_node	*curr;
	int		i;

	i = p->np - 1;
	if (p->np < 0)
		i = stack_a->size + p->np;
	curr = stack_a->last;
	while (i > 0)
	{
		curr = curr->prev;
		i--;
	}
	if (curr->val < p->pivot_val[0])
		p->group = Z;
	else if (curr->val < p->pivot_val[1])
		p->group = Y;
	else if (curr->val < p->pivot_val[2])
		p->group = X;
}

static void	log_base_three_partition(t_dlst *stack_a, t_dlst *stack_b, int *sort)
{
	t_partition p;

	p.to_rr = 0;
	log_base_three_pivot(sort, p.pivot_val, stack_a->size);
	p.np = nearest_to_push(stack_a, p.pivot_val);
	while (p.np != 0)
	{
		divided_groups(stack_a, &p);
		smart_rotate_partition(stack_a, stack_b, &p);
		p.np = nearest_to_push(stack_a, p.pivot_val);
	}
	if (p.to_rr > 0)
		rotate_count(stack_b, B, p.to_rr);
}


void	smart_partition(t_dlst *stack_a, t_dlst *stack_b)
{
	int	*sort;

	while (stack_a->size > 5)
	{
		sort = selection_sort(stack_a, stack_a->first);
		log_base_three_partition(stack_a, stack_b, sort);
		free(sort);
	}
}