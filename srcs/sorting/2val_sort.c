/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2val_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:34 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/16 17:13:28 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	two_val_sort(t_dlst *stack, int s)
{
	int	top_val;
	int	bot_val;

	top_val = stack->last->val;
	bot_val = stack->last->prev->val;
	if (s == A && top_val > bot_val)
		swap(stack, A);
	else if (s == B && top_val < bot_val)
		swap(stack, B);
}
