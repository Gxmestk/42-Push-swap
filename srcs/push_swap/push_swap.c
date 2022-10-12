/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:45:54 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 15:25:07 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc,char **argv)
{
	static t_dlst	stack_A;
	//static t_dlst	stack_B;

	check_args(&stack_A, argc, argv);
	dlst_print(&stack_A);
	ft_printf("\n%d\n",dlst_isempty(&stack_A));
	ft_printf("\n%d\n",dlst_issort(&stack_A, stack_A.first, ASC));
	swap(&stack_A);
	dlst_print(&stack_A);
	rotate(&stack_A);
	dlst_print(&stack_A);
	swap(&stack_A);
	dlst_print(&stack_A);
	swap(&stack_A);
	rrotate(&stack_A);
	swap(&stack_A);
	dlst_print(&stack_A);
	dlst_free(&stack_A);
	return (0);
}
