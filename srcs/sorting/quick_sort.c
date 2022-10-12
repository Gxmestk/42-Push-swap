/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:46:29 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/12 17:34:01 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	quick_sort(t_dlst *this, t_dlst *that, t_node *end, int s)
{
	if (dlst_node_count(this, end) == 3)
		three_val_sort(this, end, s);
	else if (dlst_node_count(this, end) == 2)
		two_val_sort(this, s);
	that++;
}