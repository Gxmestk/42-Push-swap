/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:13 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/18 20:34:15 by tkhemniw         ###   ########.fr       */
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

void	push_back_atmost(t_dlst *stack_from, t_dlst *stack_to, int s, int n)
{
	int	i;

	i = 0;
	while (!dlst_isempty(stack_from) && i < n)
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

int	nearest_to_push(t_dlst *stack_a, int *pivot_val)
{
	int		i;
	t_node	*curr;
	int		ret;

	curr = stack_a->last;
	i = 1;
	while (curr != NULL && curr->val >= pivot_val[1])
	{
		curr = curr->prev;
		i++;
	}
	if (curr == NULL)
		return (0);
	ret = i;
	i = -1;
	curr = stack_a->first;
	while (curr != NULL && curr->val >= pivot_val[1])
	{
		curr = curr->next;
		i--;
	}
	if (-i < ret - 1)
		ret = i;
	return (ret);
}
