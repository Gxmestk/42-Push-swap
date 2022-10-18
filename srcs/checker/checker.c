/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:42 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/18 20:33:28 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	do_a_instr(t_dlst *stack_a, t_dlst *stack_b, char *instr)
{
	if (!ft_strncmp(instr, "sa\n", 4))
		swap(stack_a, NO);
	else if (!ft_strncmp(instr, "sb\n", 4))
		swap(stack_b, NO);
	else if (!ft_strncmp(instr, "ss\n", 4))
		swap_swap(stack_a, stack_b, NO);
	else if (!ft_strncmp(instr, "pa\n", 4))
		push(stack_b, stack_a, NO);
	else if (!ft_strncmp(instr, "pb\n", 4))
		push(stack_a, stack_b, NO);
	else if (!ft_strncmp(instr, "ra\n", 4))
		rotate(stack_a, NO);
	else if (!ft_strncmp(instr, "rb\n", 4))
		rotate(stack_b, NO);
	else if (!ft_strncmp(instr, "rr\n", 4))
		rotate_rotate(stack_a, stack_b, NO);
	else if (!ft_strncmp(instr, "rra\n", 5))
		rrotate(stack_a, NO);
	else if (!ft_strncmp(instr, "rrb\n", 5))
		rrotate(stack_b, NO);
	else if (!ft_strncmp(instr, "rrr\n", 5))
		rrotate_rrotate(stack_a, stack_b, NO);
	else
		error_free2(stack_a, stack_b);
}

static void	checker(t_dlst *stack_a, t_dlst *stack_b)
{
	char	*instr;

	instr = get_next_line(STDIN_FILENO);
	while (instr)
	{
		do_a_instr(stack_a, stack_b, instr);
		free(instr);
		instr = get_next_line(STDIN_FILENO);
	}
	free(instr);
	if (dlst_issort(stack_a, stack_a->first, ASC) && dlst_isempty(stack_b))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	static t_dlst	stack_a;
	static t_dlst	stack_b;

	if (argc == 1 || (argc == 2 && ft_strlen(argv[1]) == 0))
		return (0);
	check_args(&stack_a, argc, argv);
	checker(&stack_a, &stack_b);
	dlst_free(&stack_a);
	dlst_free(&stack_b);
	return (0);
}
