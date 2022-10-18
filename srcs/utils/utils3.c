/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:32:40 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/18 20:37:13 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_node	*min_val_node(t_dlst *stack)
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

t_node	*max_val_node(t_dlst *stack)
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

static void	next_min_val_index(int *arr, int size, int *mvi, int *nmvi)
{
	int	i;

	i = 0;
	if (*mvi == 0)
		i = 1;
	*nmvi = i;
	while (i < size)
	{
		if (arr[i] < arr[*nmvi] && i != *mvi)
			*nmvi = i;
		i++;
	}
}

void	max_val_index(int *arr, int size, int *mvi, int *nmvi)
{
	int	i;

	i = 0;
	*mvi = i;
	while (i < size)
	{
		if (arr[i] < arr[*mvi])
			*mvi = i;
		i++;
	}
	next_min_val_index(arr, size, mvi, nmvi);
}

void	copy_stack_to_arr_nomal(t_dlst *stack, int *arr, int size)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = stack->last;
	while (i < size)
	{
		arr[i] = curr->val;
		curr = curr->prev;
		i++;
	}
}
