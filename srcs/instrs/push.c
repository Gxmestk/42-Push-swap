/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:13 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/14 20:31:00 by tkhemniw         ###   ########.fr       */
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
}

void	push_back_count(t_dlst *stack_from, t_dlst *stack_to, int s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		push(stack_from, stack_to, s);
		i++;
	}
}

void	push_back_all(t_dlst *stack_from, t_dlst *stack_to, int s)
{
	while (!dlst_isempty(stack_from))
	{
		push(stack_from, stack_to, s);
	}
}