/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazy_sort1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:04:02 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/17 04:33:44 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static t_node	*mini_placable(t_dlst *stack_a, t_node *node, t_r *l)
{
	t_node	*curr;
	int		i;
	t_node	*ret;

	i = 0;
	curr = stack_a->last;
	ret = NULL;
	while (curr != NULL)
	{
		if (curr->val > node->val && (ret == NULL || curr->val < ret->val))
		{
			if (i > stack_a->size / 2)
				l->rra = stack_a->size - i;
			else
				l->ra = i;
			ret = curr;
		}
		i++;
		curr = curr->prev;
	}
	return (ret);
}

static void set_current_mini(t_dlst *stack_b, t_r *p, t_r *l)
{
	l->move = max_two(l->ra, l->rb) + max_two(l->rra, l->rrb);
	if (l->move > p->move && p->a != NULL)
		return ;
	if (p->a == NULL || (l->b == max_val_node(stack_b))
		|| (l->a->index - l->b->index < p->a->index - p->b->index)
		|| (l->a->index - l->b->index == p->a->index - p->b->index
		&& l->b->val > p->b->val))
	{
		p->move = l->move;
		p->ra = l->ra;
		p->rb = l->rb;
		p->rra = l->rra;
		p->rrb = l->rrb;
		p->a = l->a;
		p->b = l->b;
	}
}
static void reset_mini(t_r *r)
{
	r->ra = 0;
	r->rb = 0;
	r->rra = 0;
	r->rrb = 0;
	r->a = NULL;
	r->b = NULL;
	r->move = 0;
}

static void	mini_move(t_dlst *stack_a, t_dlst *stack_b, t_r *p)
{
	t_r		l;
	t_node	*curr;
	int		i;

	i = 0;
	curr = stack_b->last;
	reset_mini(p);
	while (curr != NULL)
	{	
		if (curr->label == p->lab)
		{
			reset_mini(&l);
			if (i > stack_b->size / 2)
				l.rrb = stack_b->size - i;
			else
				l.rb = i;
			l.b = curr;
			l.a = mini_placable(stack_a, curr, &l);
			set_current_mini(stack_b, p, &l);
		}
		i++;
		curr = curr->prev;
	}
}

void	lazy_sort(t_dlst *stack_a, t_dlst *stack_b)
{
	t_r	p;

	if (dlst_issort(stack_a, stack_a->first, ASC))
		return ;
	smart_partition(stack_a, stack_b);
	hardcode_sort(stack_a, stack_b);
	p.lab = stack_b->last->label;
	while (!dlst_isempty(stack_b))
	{
		mini_move(stack_a, stack_b, &p);
		do_instr(stack_a, stack_b, &p);
		if (!any_curr_lab(stack_b, p.lab))
			p.lab--;
	}
	while (stack_a->first != max_val_node(stack_a))
		rrotate(stack_a, A);
}