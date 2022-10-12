/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:14:02 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 21:16:47 by tkhemniw         ###   ########.fr       */
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

	i = 0;
	if (!ft_isdigit(argv1[0]))
		error_log();
	while (argv1[i] != '\0')
	{
		if (argv1[i] == '-' || argv1[i] == '+')
			i++;
		while ((ft_isdigit(argv1[i])))
			i++;
		if (argv1[i] == ' ')
			i++;
		else if (argv1[i] != '\0')
			error_log();
	}
}

void	ft_isnumeric_2d(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == '-'
				|| argv[i][j] == '+'))
				error_log();
			j++;
		}
		i++;
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
