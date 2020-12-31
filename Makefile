all:
	make -C ./42_libft/
	gcc -c ft_strcpy.c
	gcc -c ft_strcmp.c
	cp ./42_libft/libft.a ./libasm.a
	ar -rcs libasm.a ft_strcpy.o ft_strcmp.o
