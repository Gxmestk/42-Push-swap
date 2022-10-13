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

t_node	*min_val_node(t_dlst *stack)
{
	t_node	*min;
	t_node	*curr;

	curr = stack->last;
	while (curr != stack->first)
	{
		if (curr->prev->val < curr->val)
			min = curr->prev;
		curr = curr->prev;
	}
	return (min);
}

t_node	*max_val_node(t_dlst *stack)
{
	t_node	*max;
	t_node	*curr;

	curr = stack->last;
	while (curr != stack->first)
	{
		if (curr->prev->val > curr->val)
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
			curr = stack->last;
			ncurr = stack->first;
			if (((curr == max && curr->prev == min) || curr->val <= curr->prev->val) && ncurr->next->val < ncurr->val)
				rotate(stack, s);
			else if (((ncurr == max && ncurr->next == min) || ncurr->next->val > ncurr->val) && curr->prev->val > curr->val)
				rrotate(stack, s);
			else if (curr->val > curr->prev->val)
				swap(stack, s);
			else
				rotate(stack, s);
			if (i == 10)
				break ;
			i++;
		}
	}
	/*else if (s == B)
	{
		
	}*/
}