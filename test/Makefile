NAME		=	libasm_test
LIBASM		=	../libasm.a

SRCS		=	srcs/main.c		\
				srcs/parse.c	\
				srcs/test_strlen.c	\
				srcs/test_strcpy.c	\
				srcs/test_strcmp.c
OBJS		=	$(SRCS:.c=.o)

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -I ./

all			:	$(NAME)

libasm		:
				make -C ../

$(NAME)		:	libasm $(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(LIBASM)

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean $(NAME)

.PHONY		:	all clean fclean re
