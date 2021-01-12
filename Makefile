NAME	=	libasm.a

SRCS	=	srcs/ft_strlen.s
OBJS	=	$(SRCS:.s=.o)

ASMC	=	nasm
ASMFLAGS=	-f elf64

all		:	$(NAME)

.s.o:
			$(ASMC) $(ASMFLAGS) -o $(<:.s=.o) $<

$(NAME)	:	$(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean $(NAME)

.PHONY	:	all clean fclean re
