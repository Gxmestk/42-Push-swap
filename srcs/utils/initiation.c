/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:45:58 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 21:21:02 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static	t_node	*newnode(t_dlst *stack_a, int val)
{
	t_node	*node;

	ft_isdup(stack_a, val);
	node = malloc(sizeof(t_node));
	if (!node)
		error_free(stack_a);
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	to_dlst_1d(t_dlst *stack_a, char *argv1)
{
	t_node	*tmp;

	while (*argv1 != '\0')
	{
		tmp = newnode(stack_a, (int)ft_atol(stack_a, &argv1));
		dlst_addfront(stack_a, tmp);
		if (*argv1 == ' ' && *(argv1 + 1) == '\0')
			error_free_log(stack_a);
		else if (*argv1 == ' ')
			argv1++;
	}
}

static void	to_dlst_2d(t_dlst *stack_a, int argc, char **argv)
{
	int		i;
	t_node	*tmp;

	i = 1;
	while (i < argc)
	{
		tmp = newnode(stack_a, (int)ft_atol(stack_a, &argv[i]));
		dlst_addfront(stack_a, tmp);
		i++;
	}
}

void	check_args(t_dlst *stack_a, int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		exit(0);
	else if (argc == 2)
	{
		ft_isnumeric_1d(argv[1]);
		to_dlst_1d(stack_a, argv[1]);
	}
	else
	{
		ft_isnumeric_2d(argv);
		to_dlst_2d(stack_a, argc, argv);
	}
}
