/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:45:54 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/16 20:19:44 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_dlst	stack_a;
	static t_dlst	stack_b;

	check_args(&stack_a, argc, argv);
	if (stack_a.size > 5)
		lazy_sort(&stack_a, &stack_b);
	else
		hardcode_sort(&stack_a, &stack_b);

	//ft_printf("\nresult\n");
	//dlst_print(&stack_a, A);
	dlst_free(&stack_a);
	return (0);
}