/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4val_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:31:41 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/16 23:05:46 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	four_val_sort(t_dlst *stack_a, t_dlst *stack_b, int s)
{
	t_small	f;

	copy_stack_to_arr_nomal(stack_a, f.arr, 4);
	max_val_index(f.arr, 4, &f.mvi, &f.nmvi);
	if (f.mvi == 1 && (f.nmvi == 0 || f.nmvi == 3))
		swap(stack_a, A);
	else if (f.mvi == 1 && (f.nmvi == 2))
		rotate(stack_a, A);
	else if (f.mvi == 2)
	{
		rotate(stack_a, A);
		if (f.nmvi == 1)
			rotate(stack_a, A);
		else
			swap(stack_a, A);
	}
	else if (f.mvi == 3)
		rrotate(stack_a, A);
	if (!dlst_issort(stack_a, stack_a->first, ASC))
	{
		push(stack_a, stack_b, A);
		three_val_sort(stack_a, stack_a->first, s);
	}
	push_back_atmost(stack_b, stack_a, B, 1);
}
