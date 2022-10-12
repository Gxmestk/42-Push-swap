/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:01:58 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 21:17:01 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	error_log(void)
{
	write(2, "Error", 5);
	exit(1);
}

void	error_free(t_dlst *stack_a)
{
	dlst_free(stack_a);
	exit(1);
}

void	error_free2(t_dlst *stack_a, t_dlst *stack_b)
{
	dlst_free(stack_a);
	dlst_free(stack_b);
	exit(1);
}

void	error_free_log(t_dlst *stack_a)
{
	dlst_free(stack_a);
	error_log();
}
