/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:29 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 21:17:01 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static int	smart_pivot(t_dlst *this, t_node *end)
{
	int	ret;

	ret = selection_sort(this, end);
	return (ret);
}

static void	quick_sort_b()
{
}

void	quick_sort_a(t_dlst *stack_a, t_dlst *stack_b, t_node *end, int s)
{
	int		nc;
	int 	pivot;
	t_node	*that_end;

	ft_printf("START quick_sort\n");
	ft_printf("this\n");
	dlst_print(this);
	ft_printf("that\n");
	dlst_print(that);
	nc = dlst_node_count(this, end);
	pivot = smart_pivot(this, end);
	that_end = NULL;
	if (dlst_issort(this, end, s))
		return ;
	if (nc == 3)
		three_val_sort(this, end, s);
	else if (nc == 2)
		two_val_sort(this, s);
	else
	{
		while (nc > 0)
		{
			if (this->last->val < pivot)
			{
				if (!that_end)
					that_end = this->last;
				push(this, that, s);
			}
			else
				rotate(this, s);
			nc--;
		}
		if (s == A)
		{
			quick_sort(this, that, end, A);
			quick_sort(that, this, that_end, B);
		}
		else if (s == B)
		{
			quick_sort(that, this, that_end, A);
			quick_sort(this, that, end, B);
		}
	}
}
