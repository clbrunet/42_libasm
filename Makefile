NAME	=	libasm.a

SRCS	=	srcs/ft_strlen.s	\
			srcs/ft_strcpy.s	\
			srcs/ft_strcmp.s	\
			srcs/ft_write.s		\
			srcs/ft_read.s		\
			srcs/ft_strdup.s
OBJS	=	$(SRCS:.s=.o)

ASMC	=	nasm
ASMFLAGS=	-f elf64 -g

all		:	$(NAME)

.s.o:
			$(ASMC) $(ASMFLAGS) -o $(<:.s=.o) $<

$(NAME)	:	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean $(NAME)

.PHONY	:	all clean fclean re
