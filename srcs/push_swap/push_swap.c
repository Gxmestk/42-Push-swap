/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:45:54 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/13 11:45:24 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_dlst	stack_a;
	//static t_dlst	stack_b;

	check_args(&stack_a, argc, argv);
	ft_printf("\ninit\n");
	dlst_print(&stack_a, A);
	//quick_sort(&stack_a, &stack_b, stack_a.first, ASC);
	easy_sort(&stack_a, A);
	ft_printf("result\n");
	dlst_print(&stack_a, A);
	return (0);
}
