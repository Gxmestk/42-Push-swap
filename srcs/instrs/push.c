/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:13 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 21:15:23 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void	push(t_dlst	*stack_from, t_dlst *stack_to, int s)
{
	t_node	*tmp;

	tmp = dlst_removeback(stack_from);
	dlst_addback(stack_to, tmp);
	if (s == A)
		ft_printf("pa\n");
	else if (s == B)
		ft_printf("pb\n");
	dlst_print(stack_from);
	dlst_print(stack_to);
}
