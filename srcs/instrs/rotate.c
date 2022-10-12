/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:18 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 18:51:03 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void	rotate(t_dlst *stack, int s)
{
	t_node	*tmp;

	tmp = dlst_removeback(stack);
	dlst_addfront(stack, tmp);
	if (s == A)
		ft_printf("ra\n");
	else if (s == B)
		ft_printf("rb\n");
	dlst_print(stack);
}
/*last(top) go to fisrt(bottom)*/