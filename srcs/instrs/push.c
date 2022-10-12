/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:13 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 14:44:13 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void	push(t_dlst	*stack_from, t_dlst *stack_to)
{
	t_node	*tmp;

	tmp = dlst_removeback(stack_from);
	if (tmp == NULL)
		error_free2(stack_from, stack_to);
	dlst_addback(stack_to, tmp);
}