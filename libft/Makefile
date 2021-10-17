NAME =	libft.a

LIST =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c\
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_itoa.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strmapi.c \
		ft_split.c \

LIST_B =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \

OBJ =	$(patsubst %.c, %.o, $(LIST))

OBJ_B =	$(patsubst %.c, %.o, $(LIST_B))

D_FILES	=	$(patsubst %.c, %.d, $(LIST) $(LIST_B))

FLAGS	=	-Wall -Werror -Wextra

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rcs $(NAME) $?
	@echo "libft is ready to use"

%.o	:	%.c
	@gcc $(FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

bonus	:	$(OBJ_B)
	ar rcs $(NAME) $?

clean:
	@rm -f $(OBJ) $(OBJ_B) $(D_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
