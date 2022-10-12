/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:21 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 14:54:14 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void	rrotate(t_dlst *stack)
{
	t_node	*tmp;

	tmp = dlst_removefront(stack);
	if (tmp == NULL)
		error_free(stack);
	dlst_addback(stack, tmp);
}
/*fisrt(bottom) go to last(top)*/