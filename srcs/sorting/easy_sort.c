/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:16:11 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/14 19:36:50 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static t_node	*min_val_node(t_dlst *stack)
{
	t_node	*min;
	t_node	*curr;

	curr = stack->last;
	min = curr;
	while (curr != stack->first)
	{
		if (curr->prev->val < min->val)
			min = curr->prev;
		curr = curr->prev;
	}
	return (min);
}

static t_node	*max_val_node(t_dlst *stack)
{
	t_node	*max;
	t_node	*curr;

	curr = stack->last;
	max = curr;
	while (curr != stack->first)
	{
		if (curr->prev->val > max->val)
			max = curr->prev;
		curr = curr->prev;
	}
	return (max);
}

void	easy_sort(t_dlst *stack_a, t_dlst *stack_b, int s)
{
	t_node	*curr;
	t_node	*min;
	t_node	*max;
	t_node	*ncurr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	min = min_val_node(stack_a);
	max = max_val_node(stack_a);
	if (s == A)
	{
		while (!dlst_issort(stack_a, stack->first, ASC))
		{
			min = min_val_node(stack_a);
			ft_printf("i = %d   ", i);
			curr = stack_a->last;
			ncurr = stack_a->first;
			if (curr == min_val_node(stack_a))
			{
				push(stack_a, stack_b);
				j++;
			}
			if (((curr->val > curr->prev->val) && !(curr->prev == min && curr == max) && ncurr))
				swap(stack, s);
			else if (curr->val > stack_a->first->val)
				if (curr == min)
					swap(stack_a, s);
				else
					rotate(stack_a, s);
			else
				rrotate(stack_a, s);
			if (i == 50)
				break ;
			i++;
		}
		i = 0;
		while (i < j)
		{
			push(stack_b, stack_a);
			i++;
		}
	}
	/*else if (s == B)
	{
		
	}*/
}