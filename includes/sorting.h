/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:13:09 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/13 10:19:19 by tkhemniw         ###   ########.fr       */
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

//void	quick_sort(t_dlst *this, t_dlst *that, t_node *end, int s);
void	two_val_sort(t_dlst *stack, int s);
void	three_val_sort(t_dlst *stack, t_node *end, int s);
int		median_selection_sort(t_dlst *stack, t_node *end);
void	easy_sort(t_dlst *stack, int s);

#endif