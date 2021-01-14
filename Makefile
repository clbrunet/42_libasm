NAME	=	libasm.a

SRCS	=	srcs/ft_strlen.s
OBJS	=	$(SRCS:.s=.o)

# SRCS	=	srcs/main.c	\
			srcs/ft_strlen.s
# OBJS	=	$(OBJS:.c=.o)

ASMC	=	nasm
ASMFLAGS=	-f elf64 -g

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -g

all		:	$(NAME)

.s.o:
			$(ASMC) $(ASMFLAGS) -o $(<:.s=.o) $<
.c.o:
			$(CC) $(CFLAGS) -c -o $(<:.c=.o) $<

$(NAME)	:	$(OBJS)
			ar -rcs $(NAME) $(OBJS)
			# ld $(OBJS)
			# $(CC) $(CFLAGS) $(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean $(NAME)

.PHONY	:	all clean fclean re
