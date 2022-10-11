/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:37:08 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/11 20:38:45 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf.h"

# define ERR -1
# define NO 0
# define ASC 1
# define DESC 2
# define MERGE 1

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*asc;
}	t_node;

typedef struct s_dlst
{
	t_node	*first;
	t_node	*last;
	int		size;
}	t_dlst;

void	check_args(t_dlst *stack_A, int argc, char **argv);
int		ft_isdigit(int c);
long	ft_atol(t_dlst *stack_A, char **str);
void 	ft_isnumeric_1d(char *argv1);
void	ft_isnumeric_2d(char **argv);
void	ft_isdup(t_dlst *stack_A, int val);
void	error_log(void);
void	error_free(t_dlst *stack_A);
void	error_free_log(t_dlst *stack_A);
void	dlst_addfront(t_dlst *dlst, t_node *node);
void	dlst_addback(t_dlst *dlst, t_node *node);
void	dlst_addat(t_dlst *dlst, t_node *node, int i);
t_node	*dlst_removeback(t_dlst *dlst);
void	dlst_print(t_dlst *dlst);
int		dlst_isempty(t_dlst *dlst);
int		dlst_issort(t_dlst *dlst, t_node *end, int dir);
void	dlst_free(t_dlst *dlst);
#endif
