/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:37:08 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/18 20:33:17 by tkhemniw         ###   ########.fr       */
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
# define A 1
# define B 2
# define AB 3
# define X 33
# define Y 66
# define Z 99

typedef struct s_node
{
	int				val;
	int				index;
	int				label;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_dlst
{
	t_node	*first;
	t_node	*last;
	int		size;
}	t_dlst;

typedef struct s_partition
{
	int	pivot_val[3];
	int	np;
	int	npv;
	int	group;
	int	to_rr;
}	t_partition;

void	check_args(t_dlst *stack_a, int argc, char **argv);
int		ft_isdigit(int c);
long	ft_atol(t_dlst *stack_a, char **str);
void	ft_isnumeric_1d(char *argv1);
void	ft_isnumeric_2d(char **argv);
void	ft_isdup(t_dlst *stack_a, int val);
void	error_log(void);
void	error_free(t_dlst *stack_a);
void	error_free2(t_dlst *stack_a, t_dlst *stack_b);
void	error_free_log(t_dlst *stack_a);
int		ft_strncmp(const char *str1, const char *str2, size_t len);
void	dlst_addfront(t_dlst *dlst, t_node *node);
void	dlst_addback(t_dlst *dlst, t_node *node);
void	dlst_addat(t_dlst *dlst, t_node *node, int i);
t_node	*dlst_removeback(t_dlst *dlst);
t_node	*dlst_removefront(t_dlst *dlst);
void	dlst_print(t_dlst *dlst, int s);
int		dlst_isempty(t_dlst *dlst);
int		dlst_issort(t_dlst *dlst, t_node *end, int dir);
void	dlst_free(t_dlst *dlst);
int		dlst_node_count(t_dlst *dlst, t_node *end);
t_node	*min_val_node(t_dlst *stack);
t_node	*max_val_node(t_dlst *stack);
void	max_val_index(int *arr, int size, int *mvi, int *nmvi);
void	copy_stack_to_arr_nomal(t_dlst *stack, int *arr, int size);
#endif
