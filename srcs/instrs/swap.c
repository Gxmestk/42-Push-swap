/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:10 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/15 12:00:45 by tkhemniw         ###   ########.fr       */
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
/*last(top) go to fisrt(bottom)*/