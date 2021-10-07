# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 20:45:20 by cnorma            #+#    #+#              #
#    Updated: 2021/10/06 20:01:22 by cnorma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
SRC_DIR = ./srcs/
SRC_FILES =	main.c \
			check_stack.c \
			operations.c\
			rotate_insert1.c \
			rotate_insert2.c \
			rotate_optimizer.c \
			rotate_push.c \
			sort.c \
			sort_support.c \
			stacks.c

OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(SRC_DIR), $(OBJ_FILES))

DIR_LIBFT = libft/
LIBFT = libft/libft.a

HEADER = includes/push_swap.h

CC = gcc

LFLAGS = -Wall -Wextra -Werror -o
CFLAGS = -Wall -Wextra -Werror -c

all: $(LIBFT) $(SRCS) $(NAME) $(HEADER)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $< -o $@ -I ./includes/

$(NAME): $(OBJS) $(LIBFT) $(HEADER)
	@$(CC) $(LFLAGS) $(NAME) $(OBJS) $(LIBFT) -I ./includes/

$(LIBFT):
	@$(MAKE) -C $(DIR_LIBFT)

clean:
	@$(MAKE) clean -C $(DIR_LIBFT)

fclean: clean
	@rm -f $(NAME) $(OBJS)
	@$(MAKE) fclean -C $(DIR_LIBFT)

re: fclean all

.PHONY: all re clean fclean
