/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:10 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 14:57:53 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void	swap(t_dlst *stack)
{
	t_node	*tmp;

	tmp = dlst_removeback(stack);
	dlst_addat(stack, tmp, stack->size - 1);
}
/*last(top) go to fisrt(bottom)*/