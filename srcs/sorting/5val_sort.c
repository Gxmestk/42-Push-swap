/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5val_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:18:19 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/16 00:19:41 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	five_val_sort(t_dlst *stack_a, t_dlst *stack_b, int s)
{
	t_small	f;

	copy_stack_to_arr_nomal(stack_a, f.arr, 5);
	max_val_index(f.arr, 5, &f.mvi, &f.nmvi);
	if (f.mvi == 1 && (f.nmvi == 0 || f.nmvi == 4))
		swap(stack_a, A);
	else if (f.mvi == 1 && (f.nmvi == 2 || f.nmvi == 3))
		rotate(stack_a, A);
	else if (f.mvi == 2)
	{
		rotate(stack_a, A);
		if (f.nmvi == 3 || f.nmvi == 4)
			rotate(stack_a, A);
		else if (f.nmvi == 0 || f.nmvi == 1)
			swap(stack_a, A);
	}
	else if(f.mvi == 3 || f.mvi == 4)
		rrotate(stack_a, A);
	if (f.mvi == 3)
		rrotate(stack_a, A);
	if (dlst_issort(stack_a, stack_a->first, ASC))
		return ;
	push(stack_a, stack_b, A);
	four_val_sort(stack_a, stack_b, s);
}
