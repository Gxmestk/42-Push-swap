/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3val_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:31 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 18:47:20 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static void	tvs_opt_1instr(t_dlst *stack, int s);
static void	tvs_opt_2instr(t_dlst *stack, int s);

static void	tvs_opt_2instr(t_dlst *stack, int s)
{
	t_val	v;

	v.top = stack->last->val;
	v.mid = stack->last->prev->val;
	v.bot = stack->first->val;
	if (s == A)
	{
		if (v.top > v.mid && v.mid > v.bot)
			swap(stack, A);
		else if (v.top < v.bot && v.bot < v.mid)
			swap(stack, A);
	}
	if (s == B)
	{
		if (v.top < v.mid && v.mid < v.bot)
			swap(stack, B);
		else if (v.top > v.bot && v.bot > v.mid)
			swap(stack, B);
	}
	tvs_opt_1instr(stack, s);
}

static void	tvs_opt_1instr(t_dlst *stack, int s)
{
	t_val	v;

	v.top = stack->last->val;
	v.mid = stack->last->prev->val;
	v.bot = stack->first->val;
	if (s == A)
	{
		if (v.top > v.mid && v.top < v.bot)
			swap(stack, A);
		else if (v.top < v.mid && v.top > v.bot)
			rrotate(stack, A);
		else if (v.top > v.mid && v.mid < v.bot)
			rotate(stack, A);
	}
	else if (s == B)
	{
		if (v.top < v.mid && v.top > v.bot)
			swap(stack, B);
		else if (v.top > v.mid && v.top < v.bot)
			rrotate(stack, B);
		else if (v.top < v.mid && v.mid > v.bot)
			rotate(stack, B);
	}
	if (!dlst_issort(stack, stack->first, s))
		tvs_opt_2instr(stack, s);
}

void	three_val_sort(t_dlst *stack, t_node *end, int s)
{
	//t_val	v;

	if (dlst_issort(stack, end, s))
		return ;
	else if (stack->size == 3)
		tvs_opt_1instr(stack, s);
	else
		ft_printf("NAH\n");
}