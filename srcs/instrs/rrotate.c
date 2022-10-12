/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:21 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 16:26:52 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void	rrotate(t_dlst *stack, int s)
{
	t_node	*tmp;

	tmp = dlst_removefront(stack);
	dlst_addback(stack, tmp);
	if (s == A)
		ft_printf("rra\n");
	else if (s == B)
		ft_printf("rrb\n");
}
/*fisrt(bottom) go to last(top)*/