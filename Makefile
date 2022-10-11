# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 18:12:38 by tkhemniw          #+#    #+#              #
#    Updated: 2022/10/11 19:37:05 by tkhemniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Defaults
NAME				= push_swap
CHECKER_NAME		= checker
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
RM					= /bin/rm -f

#Directories
INCS_DIR			= ./includes
PRINTF_DIR			= ./libs/ft_printf
SRC_DIR				= ./srcs
PUSH_SWAP_DIR		= $(SRC_DIR)/push_swap
UTIL_DIR			= $(SRC_DIR)/utils
INSTR_DIR			= $(SRC_DIR)/instrs
SORTING_DIR			= $(SRC_DIR)/sorting
CHECKER_DIR			= $(SRC_DIR)/checker

#Includes
INCLUDES 			= -I $(INCS_DIR)									\
					  -I $(PRINTF_DIR)/includes

#Libraries
LIBS				= -L $(PRINTF_DIR) -lftprintf

#Source files
SRCS				= $(PUSH_SWAP_DIR)/push_swap.c						\
					  $(UTIL_SRCS)										\
					  $(INSTR_SRCS)										\
					  $(SORTING_SRCS)									\
					  $(CHECKER_SRCS)
UTIL_SRCS			= $(UTIL_DIR)/initiation.c							\
					  $(UTIL_DIR)/dlst_instrs.c							\
					  $(UTIL_DIR)/dlst_utils.c							\
					  $(UTIL_DIR)/utils1.c								\
					  $(UTIL_DIR)/utils2.c
INSTR_SRCS			= $(INSTR_DIR)/swap.c								\
					  $(INSTR_DIR)/push.c								\
					  $(INSTR_DIR)/rotate.c								\
					  $(INSTR_DIR)/rrotate.c
SORTING_SRCS		= $(SORTING_DIR)/merge_sort.c						\
					  $(SORTING_DIR)/quick_sort.c						\
					  $(SORTING_DIR)/3val_sort.c						\
					  $(SORTING_DIR)/2val_sort.c
CHECKER_SRCS		= $(CHECKER_DIR)/checker.c

#Object files 
OBJS 				= $(SRCS:%.c=%.o)
CHECKER_OBJS 		= $(CHECKER_SRCS:%.c=%.o)

#Build Directories
BUILD_DIR			= build
CHECKER_BUILD_DIR	= checker_build

#Command

#Make defaults
all:				$(NAME)

#Make ./Push_swap
$(NAME):			$(OBJS) libs
						$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

#Bonus
bonus: 				checker

#Make ./checker
checker:			$(CHECKER_NAME)

$(CHECKER_NAME): 		$(CHECKER_OBJS) libs
						$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBS) -o $(CHECKER_NAME)

#Make .a
libs:
					make -C $(PRINTF_DIR)

#.c to .o
.c.o:
					$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ -c

#Cleaner
clean:
					make clean -C $(PRINTF_DIR)
					$(RM) -r $(OBJS) $(CHECKER_OBJS)

fclean:				clean
					make fclean -C $(PRINTF_DIR)
					$(RM) $(NAME)

#Restart
re:					fclean all

code:				
					code $(SRCS)
#.PHONY
.PHONY:				all bonus checker libs clean checker_clean fclean re code