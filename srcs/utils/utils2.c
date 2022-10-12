/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:01:58 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 15:35:22 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	error_log(void)
{
	write(2, "Error", 5);
	exit(1);
}

void	error_free(t_dlst *stack_A)
{
	dlst_free(stack_A);
	exit(1);
}

void	error_free2(t_dlst *stack_A, t_dlst *stack_B)
{
	dlst_free(stack_A);
	dlst_free(stack_B);
	exit(1);
}

void	error_free_log(t_dlst *stack_A)
{
	dlst_free(stack_A);
	error_log();
}
