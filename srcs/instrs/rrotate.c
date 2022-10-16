/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:21 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/17 00:16:15 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

static void	rrotate_rotate(t_dlst *stack_a, t_dlst *stack_b)
{
	t_node	*tmp;

	tmp = dlst_removefront(stack_a);
	dlst_addback(stack_a, tmp);
	tmp = dlst_removefront(stack_b);
	dlst_addback(stack_b, tmp);
	ft_printf("rrr\n");
}

void	rrotate_rotate_count(t_dlst *stack_a, t_dlst *stack_b, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		return ;
	while (i < n)
	{
		rrotate_rotate(stack_a, stack_b);
		i++;
	}
	
}

void	rrotate_count(t_dlst *stack, int s, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		return ;
	while (i < n)
	{
		rrotate(stack, s);
		i++;
	}
}

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