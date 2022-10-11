/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_instrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:01 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/11 19:48:32 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	dlst_addfront(t_dlst *dlst, t_node *node)
{
	if (node == NULL || dlst == NULL)
		return ;
	if (dlst_isempty(dlst))
		dlst->last = node;
	else
	{
		node->next = dlst->first;
		dlst->first->prev = node;
	}
	dlst->first = node;
	dlst->size++;
}

void	dlst_addback(t_dlst *dlst, t_node *node)
{
	if (node == NULL || dlst == NULL)
		return ;
	if (dlst_isempty(dlst))
		dlst->first = node;
	else
	{
		dlst->last->next = node;
		node->prev = dlst->last;
	}
	dlst->last = node;
	dlst->size++;
}

void	dlst_addat(t_dlst *dlst, t_node *node, int i)
{
	t_node	*curr;

	if (node == NULL || dlst == NULL)
		return ;
	if (i == 0)
		dlst_addfront(dlst, node);
	else if (i == dlst->size)
		dlst_addback(dlst, node);
	else if (i > 0 && i < dlst->size)
	{
		curr = dlst->first;
		while (i > 1)
		{
			curr = curr->next;
			i--;
		}
		node->prev = curr;
		node->next = curr->next;
		curr->next = node;
		node->next->prev = node;
		dlst->size++;
	}
}

t_node	*dlst_removeback(t_dlst *dlst)
{
	t_node	*ret;

	if (dlst == NULL || dlst_isempty(dlst))
		return (NULL);
	ret = dlst->last;
	dlst->last->prev->next = NULL;
	dlst->last = dlst->last->prev;
	dlst->size--;
	return (ret);
}

void	dlst_free(t_dlst *dlst)
{
	t_node	*curr;
	t_node	*tmp;

	curr = dlst->first;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}
