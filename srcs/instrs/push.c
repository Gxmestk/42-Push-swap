/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:13 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/13 13:02:36 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void	push(t_dlst	*stack_from, t_dlst *stack_to, int s)
{
	t_node	*tmp;

	tmp = dlst_removeback(stack_from);
	dlst_addback(stack_to, tmp);
	if (s == A)
		ft_printf("pb\n");
	else if (s == B)
		ft_printf("pa\n");
	/*if (s == A)
	{
		dlst_print(stack_from, A);
		dlst_print(stack_to, B);
	}
	else if (s == B)
	{
		dlst_print(stack_from, B);
		dlst_print(stack_to, A);
	}*/
}
