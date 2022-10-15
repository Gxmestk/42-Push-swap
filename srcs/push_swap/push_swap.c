/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:45:54 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/16 00:20:21 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_dlst	stack_a;
	static t_dlst	stack_b;

	check_args(&stack_a, argc, argv);
	if (stack_a.size == 5)
		five_val_sort(&stack_a, &stack_b, A);
	else if (stack_a.size == 4)
		four_val_sort(&stack_a, &stack_b, A);
	else if (stack_a.size == 3)
		three_val_sort(&stack_a, stack_a.first, A);
	else if (stack_a.size == 2)
		two_val_sort(&stack_a, A);
	else
		smart_partition(&stack_a, &stack_b);
	dlst_free(&stack_a);
	return (0);
}