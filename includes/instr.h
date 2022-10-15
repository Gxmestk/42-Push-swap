/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:13:07 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/16 00:49:10 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTR_H
# define INSTR_H

# include "utils.h"

typedef struct s_partition
{
	int	pivot_val[3];
	int	np;
	int	npv;
	int	group;
	int	to_rr;
}	t_partition;

void	rotate(t_dlst *stack, int s);
void	rotate_count(t_dlst *stack, int s, int n);
void	rotate_rotate_count(t_dlst *stack_a, t_dlst *stack_b, int n);
void	smart_rotate_partition(t_dlst *stack_a, t_dlst *stack_b, t_partition *p);
void	rrotate(t_dlst *stack, int s);
void	rrotate_count(t_dlst *stack, int s, int n);
void	swap(t_dlst *stack, int s);
void	push(t_dlst	*stack_from, t_dlst *stack_to, int s);
void	push_back_count(t_dlst *stack_from, t_dlst *stack_to, int s, int n);
void	push_back_all(t_dlst *stack_from, t_dlst *stack_to, int s);
void	push_back_atmost(t_dlst *stack_from, t_dlst *stack_to, int s, int n);
int		nearest_to_push(t_dlst *stack_a, int *pivot_val);
#endif