/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:45:54 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 21:17:15 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_dlst	stack_a;
	static t_dlst	stack_b;

	check_args(&stack_a, argc, argv);
	dlst_print(&stack_a);
	quick_sort(&stack_a, &stack_b, stack_a.first, ASC);
	ft_printf("result\n");
	dlst_print(&stack_a);
	return (0);
}
