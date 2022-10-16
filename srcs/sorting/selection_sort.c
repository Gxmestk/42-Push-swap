/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:26 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/17 00:31:10 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static void	swap_val(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	min_index(int *arr, int i, int n)
{
	int	min_i;

	min_i = i;
	while (i < n)
	{
		if (arr[i] < arr[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

static int	*copy_stack_to_arr(t_dlst *stack, t_node *end, int n)
{
	int		*unsorted;
	t_node	*curr;

	unsorted = (int *)malloc(sizeof(int) * n);
	curr = stack->last;
	n--;
	while (curr != end->prev)
	{
		unsorted[n] = curr->val;
		curr = curr->prev;
		n--;
	}
	return (unsorted);
}

int	*selection_sort(t_dlst *stack, t_node *end)
{
	int		*sort;
	int		n;
	int		i;
	int		min_i;

	n = dlst_node_count(stack, end);
	sort = copy_stack_to_arr(stack, end, n);
	i = 0;
	while (i < n)
	{
		min_i = min_index(sort, i, n);
		swap_val(&sort[i], &sort[min_i]);
		i++;
	}
	return (sort);
}

void	arg_sort(t_dlst *stack_a, int *sort)
{
	t_node	*curr;
	int		i;

	curr = stack_a->last;
	while (curr != NULL)
	{
		i = 0;
		while (i < stack_a->size)
		{
			if (curr->val == sort[i])
			{
				curr->index = i;
				break ;
			}
			i++;
		}
		curr = curr->prev;
	}
}
/*static int	max_index(int *arr, int i, int n)
{
	int	max_i;

	max_i = i;
	while (i < n)
	{
		if (arr[i] > arr[max_i])
			max_i = i;
		i++;
	}
	return (max_i);
}*/
