/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:10 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/17 13:21:06 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void	swap(t_dlst *stack, int s)
{
	t_node	*tmp;

	tmp = dlst_removeback(stack);
	dlst_addat(stack, tmp, stack->size - 1);
	if (s == A)
		ft_printf("sa\n");
	else if (s == B)
		ft_printf("sb\n");
}

void	swap_swap(t_dlst *stack_a, t_dlst *stack_b, int s)
{
	swap(stack_a,NO);
	swap(stack_b, NO);
	if (s == AB)
		ft_printf("ss\n");
}
/*last(top) go to fisrt(bottom)*/