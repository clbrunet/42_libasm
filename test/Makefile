NAME		=	libasm_test

LIBASM		=	../libasm.a
LIBASM_SRCS	:=	$(shell if test -f "../srcs/ft_strlen.s"; then echo "../srcs/ft_strlen.s"; fi)	\
				$(shell if test -f "../srcs/ft_strcpy.s"; then echo "../srcs/ft_strcpy.s"; fi)	\
				$(shell if test -f "../srcs/ft_strcmp.s"; then echo "../srcs/ft_strcmp.s"; fi)	\
				$(shell if test -f "../srcs/ft_write.s"; then echo "../srcs/ft_write.s"; fi)	\
				$(shell if test -f "../srcs/ft_read.s"; then echo "../srcs/ft_read.s"; fi)		\
				$(shell if test -f "../srcs/ft_strdup.s"; then echo "../srcs/ft_strdup.s"; fi)
LIBASM_OBJS	=	$(LIBASM_SRCS:.s=.o)

LIBASMB_SRCS:=	$(shell if test -f "../srcs/ft_atoi_base_bonus.s"; then echo "../srcs/ft_atoi_base_bonus.s"; fi)				\
				$(shell if test -f "../srcs/ft_list_push_front_bonus.s"; then echo "../srcs/ft_list_push_front_bonus.s"; fi)	\
				$(shell if test -f "../srcs/ft_list_size_bonus.s"; then echo "../srcs/ft_list_size_bonus.s"; fi)				\
				$(shell if test -f "../srcs/ft_list_sort_bonus.s"; then echo "../srcs/ft_list_sort_bonus.s"; fi)				\
				$(shell if test -f "../srcs/ft_list_remove_if_bonus.s"; then echo "../srcs/ft_list_remove_if_bonus.s"; fi)
LIBASMB_OBJS=	$(LIBASMB_SRCS:.s=.o)

LIBASM_RULE	:=	$(shell if ls ../srcs/*_bonus.s 1> /dev/null 2>&1; then echo "libasm_bonus"; else echo "libasm"; fi)

FT_STRLEN	:=	$(shell if test -f "../srcs/ft_strlen.s"; then echo "1"; else echo "0"; fi)
FT_STRCPY	:=	$(shell if test -f "../srcs/ft_strcpy.s"; then echo "1"; else echo "0"; fi)
FT_STRCMP	:=	$(shell if test -f "../srcs/ft_strcmp.s"; then echo "1"; else echo "0"; fi)
FT_WRITE	:=	$(shell if test -f "../srcs/ft_write.s"; then echo "1"; else echo "0"; fi)
FT_READ		:=	$(shell if test -f "../srcs/ft_read.s"; then echo "1"; else echo "0"; fi)
FT_STRDUP	:=	$(shell if test -f "../srcs/ft_strdup.s"; then echo "1"; else echo "0"; fi)

BONUS_PRESENT		:=	$(shell if ls ../srcs/*_bonus.s 1> /dev/null 2>&1; then echo "1"; else echo "0"; fi)
FT_ATOI_BASE		:=	$(shell if test -f "../srcs/ft_atoi_base_bonus.s"; then echo "1"; else echo "0"; fi)
FT_LIST_PUSH_FRONT	:=	$(shell if test -f "../srcs/ft_list_push_front_bonus.s"; then echo "1"; else echo "0"; fi)
FT_LIST_SIZE		:=	$(shell if test -f "../srcs/ft_list_size_bonus.s"; then echo "1"; else echo "0"; fi)
FT_LIST_SORT		:=	$(shell if test -f "../srcs/ft_list_sort_bonus.s"; then echo "1"; else echo "0"; fi)
FT_LIST_REMOVE_IF	:=	$(shell if test -f "../srcs/ft_list_remove_if_bonus.s"; then echo "1"; else echo "0"; fi)

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
				srcs/test_ft_atoi_base.c		\
				srcs/test_ft_list_size.c		\
				srcs/test_ft_list_push_front.c	\
				srcs/test_ft_list_sort.c		\
				srcs/test_ft_list_remove_if.c
OBJS		=	$(SRCS:.c=.o)

CC			=	clang
DEFINES		=	-D BONUS_PRESENT=$(BONUS_PRESENT) -D FT_STRLEN=$(FT_STRLEN) -D FT_STRCPY=$(FT_STRCPY) \
				-D FT_STRCMP=$(FT_STRCMP) -D FT_WRITE=$(FT_WRITE) -D FT_READ=$(FT_READ) \
				-D FT_STRDUP=$(FT_STRDUP) -D FT_ATOI_BASE=$(FT_ATOI_BASE) -D FT_LIST_PUSH_FRONT=$(FT_LIST_PUSH_FRONT) \
			  	-D FT_LIST_SIZE=$(FT_LIST_SIZE) -D FT_LIST_SORT=$(FT_LIST_SORT) -D FT_LIST_REMOVE_IF=$(FT_LIST_REMOVE_IF)
CFLAGS		=	-Wall -Wextra -Werror -I ./ -I ../ $(DEFINES) -g3

all			:	$(NAME)

libasm		:
				make -C ../

libasm_bonus:
				make -C ../ bonus

$(NAME)		:	$(LIBASM_SRCS) $(LIBASMB_SRCS) $(OBJS)
				@$(MAKE) $(LIBASM_RULE)
				$(CC) -g3 -o $(NAME) $(OBJS) $(LIBASM)

clean		:
				make -C ../ clean
				rm -f $(OBJS)

test_clean	:
				rm -f $(OBJS)

fclean		:	test_clean
				rm -f $(NAME)
				make -C ../ fclean

test_fclean	:	test_clean
				rm -f $(NAME)

libasm_re	:
				make -C ../ re

re			:	test_fclean libasm_re $(NAME)

.PHONY		:	all libasm libasm_bonus .s.o clean test_clean fclean test_fclean libasm_re re
