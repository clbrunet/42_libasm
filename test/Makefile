NAME		=	libasm_test
LIBASM		=	../libasm.a

FT_STRLEN	:=	$(shell if test -f "../srcs/ft_strlen.s"; then echo "1"; else echo "0"; fi)
FT_STRCPY	:=	$(shell if test -f "../srcs/ft_strcpy.s"; then echo "1"; else echo "0"; fi)
FT_STRCMP	:=	$(shell if test -f "../srcs/ft_strcmp.s"; then echo "1"; else echo "0"; fi)
FT_WRITE	:=	$(shell if test -f "../srcs/ft_write.s"; then echo "1"; else echo "0"; fi)
FT_READ		:=	$(shell if test -f "../srcs/ft_read.s"; then echo "1"; else echo "0"; fi)
FT_STRDUP	:=	$(shell if test -f "../srcs/ft_strdup.s"; then echo "1"; else echo "0"; fi)

FT_ATOI_BASE		:=	$(shell if test -f "../srcs/ft_atoi_base.s"; then echo "1"; else echo "0"; fi)
FT_LIST_PUSH_FRONT	:=	$(shell if test -f "../srcs/ft_list_push_front.s"; then echo "1"; else echo "0"; fi)
FT_LIST_SIZE		:=	$(shell if test -f "../srcs/ft_list_size.s"; then echo "1"; else echo "0"; fi)
FT_LIST_SORT		:=	$(shell if test -f "../srcs/ft_list_sort.s"; then echo "1"; else echo "0"; fi)
FT_LIST_REMOVE_IF	:=	$(shell if test -f "../srcs/ft_list_remove_if.s"; then echo "1"; else echo "0"; fi)

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
CFLAGS		=	-Wall -Wextra -Werror -I ./ -I ../ $(DEFINES) -g3

all			:	$(NAME)

libasm		:
				make -C ../

$(NAME)		:	libasm $(OBJS)
				$(CC) -g3 -o $(NAME) $(OBJS) $(LIBASM)

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean $(NAME)

.PHONY		:	all clean fclean re
