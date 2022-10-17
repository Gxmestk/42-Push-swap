/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:22:45 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/17 12:33:23 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FILES
#  define MAX_FILES 1000
# endif

typedef struct s_gnode
{
	char			*str;
	struct s_gnode	*next;
}	t_gnode;

typedef struct s_slist
{
	struct s_gnode	*first;
	struct s_gnode	*last;
	struct s_gnode	*start;
	long long		opt_bufs;
	int				fd;
}	t_slist;

typedef struct s_slst_bufcat_packet
{
	t_gnode	*walker;
	t_gnode	*tmp;
	int		n;
	int		i;
	int		stop;
}	t_slst_bufcat_packet;

char	*ft_strchr(const char *str, int c);
void	slst_addback(t_slist *lst, char *str);
void	slst_split(t_slist *buffer, char *tmp);
void	slst_malc(t_slist *buffer, int i, int n, char **rstr);
void	slst_bufcat(char **rstr, t_slist *buffer);
char	*get_next_line(int fd);

#endif