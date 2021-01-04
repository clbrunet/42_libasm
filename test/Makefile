NAME		=	libasm_test
LIBASM		=	../libasm.a

FT_STRLEN	=	1
FT_STRCPY	=	1
FT_STRCMP	=	0
FT_WRITE	=	1
FT_READ		=	1
FT_STRDUP	=	1

FT_ATOI_BASE		=	1
FT_LIST_PUSH_FRONT	=	1
FT_LIST_SIZE		=	1
FT_LIST_SORT		=	0
FT_LIST_REMOVE_IF	=	0

SRCS		=	srcs/main.c		\
				srcs/parse.c	\
				srcs/test_ft_strlen.c	\
				srcs/test_ft_strcpy.c	\
				srcs/test_ft_strcmp.c	\
				srcs/test_ft_strdup.c	\
				srcs/test_ft_write.c	\
				srcs/test_ft_read.c		\
				srcs/ft_atoi_base_c_piscine.c	\
				srcs/ft_lstnew.c				\
				srcs/ft_list_size_libft.c		\
				srcs/ft_list_push_front_libft.c	\
				srcs/ft_lstclear.c				\
				srcs/test_ft_atoi_base.c	\
				srcs/test_ft_list_size.c
OBJS		=	$(SRCS:.c=.o)

CC			=	clang
DEFINES		=	-D FT_STRLEN=$(FT_STRLEN) -D FT_STRCPY=$(FT_STRCPY) -D FT_STRCMP=$(FT_STRCMP) \
				-D FT_WRITE=$(FT_WRITE) -D FT_READ=$(FT_READ) -D FT_STRDUP=$(FT_STRDUP) \
			  	-D FT_ATOI_BASE=$(FT_ATOI_BASE) -D FT_LIST_PUSH_FRONT=$(FT_LIST_PUSH_FRONT) \
			  	-D FT_LIST_SIZE=$(FT_LIST_SIZE) -D FT_LIST_SORT=$(FT_LIST_SORT) -D FT_LIST_REMOVE_IF=$(FT_LIST_REMOVE_IF)
CFLAGS		=	-Wall -Wextra -Werror -I ./ -g3 -fsanitize=address $(DEFINES)

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
