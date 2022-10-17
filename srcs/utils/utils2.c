/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:01:58 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/17 13:19:01 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	error_log(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_free(t_dlst *stack_a)
{
	dlst_free(stack_a);
	exit(1);
}

void	error_free2(t_dlst *stack_a, t_dlst *stack_b)
{
	dlst_free(stack_a);
	dlst_free(stack_b);
	error_log();
}

void	error_free_log(t_dlst *stack_a)
{
	dlst_free(stack_a);
	error_log();
}

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t	i;

	if (len == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0')
	{
		if (i < (len - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(str1[i]) - (unsigned char)(str2[i]));
}
