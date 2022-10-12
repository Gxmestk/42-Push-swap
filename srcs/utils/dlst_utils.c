/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:04 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 18:52:31 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	dlst_print(t_dlst *dlst)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = dlst->last;
	ft_printf("size(%ld)\n", dlst->size);
	while (curr != NULL)
	{
		ft_printf("%d | %d\n", i, curr->val);
		curr = curr->prev;
		i++;
	}
	ft_printf("-------------------\n");
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

void	dlst_free(t_dlst *dlst)
{
	t_node	*curr;
	t_node	*tmp;

	if (dlst == NULL)
		return ;
	curr = dlst->first;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}

int	dlst_node_count(t_dlst *dlst, t_node *end)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = dlst->last;
	while (curr != end->prev)
	{
		i++;
		curr = curr->prev;
	}
	return (i);
}