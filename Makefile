# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 20:45:20 by cnorma            #+#    #+#              #
#    Updated: 2021/10/17 14:47:18 by cnorma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
NAME_B = checker
SRC_DIR = ./srcs/
SRC_FILES =	push_swap.c \
			check_stack.c \
			operations.c\
			operations2.c\
			rotate_insert1.c \
			rotate_insert2.c \
			rotate_optimizer.c \
			rotate_push.c \
			sort.c \
			sort_support.c \
			stacks.c \
			stacks_order.c

SRC_FILES_B =	checker.c \
				get_next_line.c\
				operations.c\
				operations2.c\
				check_stack.c\
				stacks.c \
				stacks_order.c

OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(SRC_DIR), $(OBJ_FILES))

OBJ_FILES_B = $(SRC_FILES_B:.c=.o)
SRCS_B = $(addprefix $(SRC_DIR), $(SRC_FILES_B))
OBJS_B = $(addprefix $(SRC_DIR), $(OBJ_FILES_B))

DIR_LIBFT = libft/
LIBFT = libft/libft.a

HEADER = includes/push_swap.h

CC = gcc

LFLAGS = -Wall -Wextra -Werror -o
CFLAGS = -Wall -Wextra -Werror -c -g

all: $(NAME)

bonus: $(NAME_B)

$(SRC_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@$(CC) $(CFLAGS) $< -o $@ -I ./includes/

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(LFLAGS) $(NAME) $(OBJS) $(LIBFT) -I ./includes/
	@echo $@ is ready for use

$(NAME_B): $(LIBFT) $(OBJS_B)
	$(CC) $(LFLAGS) $(NAME_B) $(OBJS_B) $(LIBFT) -I ./includes/
	@echo $@ is ready for use

$(LIBFT):
	@$(MAKE) -C $(DIR_LIBFT) re

clean:
	@$(MAKE) clean -C $(DIR_LIBFT)
	@rm -f $(OBJS) $(OBJS_B)

fclean: clean
	@rm -f $(NAME) $(NAME_B)
	@$(MAKE) fclean -C $(DIR_LIBFT)

re: fclean all

.PHONY: all re clean fclean bonus
