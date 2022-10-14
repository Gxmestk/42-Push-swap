/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5val_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:18:19 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/15 00:13:45 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	five_val_sort(t_dlst *stack_a, t_dlst *stack_b, int s)
{
	int		arr[5];
	int		mvi;
	int		nmvi;

	copy_stack_to_arr_nomal(stack_a, arr, 5);
	max_val_index(arr, 5, &mvi, &nmvi);
	if (mvi == 0)
	{
		 
	}
}
