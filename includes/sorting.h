/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:13:09 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/16 00:18:20 by tkhemniw         ###   ########.fr       */
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

void	two_val_sort(t_dlst *stack, int s);
void	three_val_sort(t_dlst *stack, t_node *end, int s);
void	four_val_sort(t_dlst *stack_a, t_dlst *stack_b, int s);
void	five_val_sort(t_dlst *stack_a, t_dlst *stack_b, int s);
int		median_selection_sort(t_dlst *stack, t_node *end);
int		*selection_sort(t_dlst *stack, t_node *end);
void	smart_partition(t_dlst *stack_a, t_dlst *stack_b);

#endif