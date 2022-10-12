/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:13:07 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 14:58:24 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTR_H
# define INSTR_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf.h"
# include "utils.h"

void	push(t_dlst	*stack_from, t_dlst *stack_to);
void	rotate(t_dlst *stack);
void	rrotate(t_dlst *stack);
void	swap(t_dlst *stack);

#endif