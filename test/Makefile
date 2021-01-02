NAME		=	libasm_test
LIBASM		=	../libasm.a

SRCS		=	srcs/main.c		\
				srcs/parse.c	\
				srcs/test_ft_strlen.c	\
				srcs/test_ft_strcpy.c	\
				srcs/test_ft_strcmp.c	\
				srcs/test_ft_strdup.c
OBJS		=	$(SRCS:.c=.o)

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -I ./ -g3 -fsanitize=address

all			:	$(NAME)

libasm		:
				make -C ../

$(NAME)		:	libasm $(OBJS)
				$(CC) -g3 -fsanitize=address -o $(NAME) $(OBJS) $(LIBASM)

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean $(NAME)

.PHONY		:	all clean fclean re
