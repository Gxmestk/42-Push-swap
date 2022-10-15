/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:14:02 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/15 11:59:13 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_isdup(t_dlst *stack_a, int val)
{
	t_node	*curr;

	curr = stack_a->first;
	while (curr != NULL)
	{
		if (curr->val == val)
			error_free_log(stack_a);
		curr = curr->next;
	}
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_isnumeric_1d(char *argv1)
{
	int	i;
	int	anum;

	i = 0;
	anum = 0;
	if (!(ft_isdigit(argv1[0]) || argv1[0] == '-' || argv1[0] == '+'))
		error_log();
	while (argv1[i] != '\0')
	{
		if (argv1[i] == '-' || argv1[i] == '+')
			i++;
		while ((ft_isdigit(argv1[i])))
		{
			anum = 1;
			i++;
		}
		if (argv1[i] == ' ')
		{
			i++;
			anum = 0;
		}
		else if (argv1[i] != '\0' || !anum)
			error_log();
	}
}

void	ft_isnumeric_2d(char **argv)
{
	int	i;
	int	j;
	int	anum;

	i = 1;
	anum = 0;
	while (argv[i] != NULL)
	{
		j = 0;

		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while ((ft_isdigit(argv[i][j])))
		{
			anum = 1;
			j++;
		}
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] != '\0' || !anum)
			error_log();
		i++;
		anum = 0;
	}
}

long	ft_atol(t_dlst *stack_a, char **str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	if ((*str)[i] == '-')
	{
			sign = -1;
			i++;
	}
	else if ((*str)[i] == '+')
			i++;
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
			result = (result * 10) + ((*str)[i++] - 48);
	result *= sign;
	if ((sign < 0 && result < INT_MIN)
		|| (sign > 0 && result > INT_MAX))
		error_free_log(stack_a);
	*str += i;
	return (result);
}
