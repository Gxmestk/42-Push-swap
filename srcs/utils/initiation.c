/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:45:58 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/11 21:11:49 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


static	t_node	*newnode(t_dlst *stack_A, int val)
{
	t_node	*node;

	ft_isdup(stack_A, val);
	node = malloc(sizeof(t_node));
	if (!node)
		error_free(stack_A);
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	node->asc = NULL;
	return (node);
}

static void	to_dlst_1d(t_dlst *stack_A, char *argv1)
{
	t_node	*tmp;

	while (*argv1 != '\0')
	{
		tmp = newnode(stack_A, (int)ft_atol(stack_A, &argv1));
		dlst_addfront(stack_A, tmp);
		if (*argv1 == ' ' && *(argv1 + 1) == '\0')
			error_free_log(stack_A);
		else if (*argv1 == ' ')
			argv1++;
	}
}

static void	to_dlst_2d(t_dlst *stack_A, int argc, char **argv)
{
	int		i;
	t_node	*tmp;

	i = 1;
	while (i < argc)
	{
		tmp = newnode(stack_A, (int)ft_atol(stack_A, &argv[i]));
		dlst_addfront(stack_A, tmp);
		i++;
	}
}

void	check_args(t_dlst *stack_A, int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		exit(0);
	else if (argc == 2)
	{
		ft_isnumeric_1d(argv[1]);
		to_dlst_1d(stack_A, argv[1]);
	}
	else
	{
		ft_isnumeric_2d(argv);
		to_dlst_2d(stack_A, argc, argv);
	}
}
