NAME	=	libasm.a

SRCS	=	srcs/ft_strlen.s	\
			srcs/ft_strcpy.s	\
			srcs/ft_strcmp.s	\
			srcs/ft_write.s		\
			srcs/ft_read.s		\
			srcs/ft_strdup.s
OBJS	=	$(SRCS:.s=.o)

BONUS_SRCS=	$(SRCS)	\
			srcs/ft_atoi_base_bonus.s		\
			srcs/ft_list_size_bonus.s		\
			srcs/ft_create_elem_bonus.s		\
			srcs/ft_list_push_front_bonus.s	\
			srcs/ft_list_sort_bonus.s
BONUS_OBJS=	$(BONUS_SRCS:.s=.o)

ASMC	=	nasm
ASMFLAGS=	-f elf64 -g

all		:	$(NAME)

.s.o:
			$(ASMC) $(ASMFLAGS) -o $(<:.s=.o) $<

$(NAME)	:	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

bonus	:	$(BONUS_OBJS)
			ar -rcs $(NAME) $(BONUS_OBJS)

clean	:
			rm -f $(BONUS_OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean $(NAME)

.PHONY	:	all clean fclean re
