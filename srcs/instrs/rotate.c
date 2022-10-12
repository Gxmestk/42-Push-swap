/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:18 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 14:42:44 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void	rotate(t_dlst *stack)
{
	t_node	*tmp;

	tmp = dlst_removeback(stack);
	if (tmp == NULL)
		error_free(stack);
	dlst_addfront(stack, tmp);
}
/*last(top) go to fisrt(bottom)*/