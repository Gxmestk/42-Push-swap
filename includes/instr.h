/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:13:07 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 16:27:44 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTR_H
# define INSTR_H

# include "utils.h"

void	push(t_dlst	*stack_from, t_dlst *stack_to, int s);
void	rotate(t_dlst *stack, int s);
void	rrotate(t_dlst *stack, int s);
void	swap(t_dlst *stack, int s);

#endif