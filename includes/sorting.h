/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:13:09 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/17 02:35:47 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "instr.h"

typedef struct s_val
{
	int	top;
	int	mid;
	int	bot;
}	t_val;

typedef struct s_small
{
	int	arr[5];
	int	mvi;
	int	nmvi;
}	t_small;

typedef struct s_r
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		move;
	int		lab;
	t_node	*b;
	t_node	*a;
}	t_r;

void	two_val_sort(t_dlst *stack, int s);
void	three_val_sort(t_dlst *stack, t_node *end, int s);
void	four_val_sort(t_dlst *stack_a, t_dlst *stack_b, int s);
void	five_val_sort(t_dlst *stack_a, t_dlst *stack_b, int s);
void	hardcode_sort(t_dlst *stack_a, t_dlst *stack_b);
int		*selection_sort(t_dlst *stack, t_node *end);
void	arg_sort(t_dlst *stack_a, int *sort);
void	smart_partition(t_dlst *stack_a, t_dlst *stack_b);
int		only_z(t_dlst *stack_b, t_partition *p);
int		max_two(int x, int y);
int		any_curr_lab(t_dlst *stack_b, int lab);
void	lazy_sort(t_dlst *stack_a, t_dlst *stack_b);
void	do_instr(t_dlst *stack_a, t_dlst  *stack_b, t_r *p);

#endif