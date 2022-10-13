/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:16:11 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/13 14:36:04 by tkhemniw         ###   ########.fr       */
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

void	easy_sort(t_dlst *stack, int s)
{
	t_node	*curr;
	t_node	*min;
	t_node	*max;
	t_node	*ncurr;
	int		i;

	i = 0;
	min = min_val_node(stack);
	max = max_val_node(stack);
	if (s == A)
	{
		while (!dlst_issort(stack, stack->first, ASC))
		{
			ft_printf("i = %d   ", i);
			curr = stack->last;
			ncurr = stack->first;
			if (((curr->val > curr->prev->val) && !(curr->prev == min && curr == max) && ncurr))
				swap(stack, s);
			else if (curr->val > stack->first->val)
				if (curr == min)
					swap(stack, s);
				else
					rotate(stack, s);
			else
				rrotate(stack, s);
			if (i == 50)
				break ;
			i++;
		}
	}
	/*else if (s == B)
	{
		
	}*/
}