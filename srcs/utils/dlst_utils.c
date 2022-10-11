/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:04 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/11 21:33:27 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	dlst_print(t_dlst *dlst)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = dlst->last;
	ft_printf("\nsize(%ld)\n", dlst->size);
	while (curr != NULL)
	{
		ft_printf("%d | %d\n", i, curr->val);
		curr = curr->prev;
		i++;
	}
}

int	dlst_isempty(t_dlst *dlst)
{
	return (!(dlst->size));
}

int	dlst_issort(t_dlst *dlst, t_node *end, int dir)
{
	t_node	*curr;

	if (dlst == NULL || dlst_isempty(dlst) || end == NULL)
		return (ERR);
	curr = dlst->last;
	if (dir == ASC)
	{
		while (curr != end)
		{
			if (curr->val > curr->prev->val)
				return (NO);
			curr = curr->prev;
		}
		return (ASC);
	}
	else if (dir == DESC)
	{
		while (curr != end)
		{
			if (curr->val < curr->prev->val)
				return (NO);
			curr = curr->prev;
		}
		return (DESC);
	}
	return (ERR);
}
