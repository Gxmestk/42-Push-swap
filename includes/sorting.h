/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:13:09 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/16 15:41:38 by tkhemniw         ###   ########.fr       */
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
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		move;
	t_node	*b;
	t_node	*a;
}	t_r;

void	two_val_sort(t_dlst *stack, int s);
void	three_val_sort(t_dlst *stack, t_node *end, int s);
void	four_val_sort(t_dlst *stack_a, t_dlst *stack_b, int s);
void	five_val_sort(t_dlst *stack_a, t_dlst *stack_b, int s);
void	hardcode_sort(t_dlst *stack_a, t_dlst *stack_b);
int		*selection_sort(t_dlst *stack, t_node *end);
void	smart_partition(t_dlst *stack_a, t_dlst *stack_b);
int		max_two(int x, int y);
void	lazy_sort(t_dlst *stack_a, t_dlst *stack_b);
void	do_instr(stack_a, stack_b, &p);


#endif