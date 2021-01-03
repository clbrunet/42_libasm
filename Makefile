all:
	make -C ./42_libft/
	clang -c ft_strcpy.c -g3 -fsanitize=address
	clang -c ft_strcmp.c -g3 -fsanitize=address
	clang -c ft_write.c -g3 -fsanitize=address
	cp ./42_libft/libft.a ./libasm.a
	ar -rcs libasm.a ft_strcpy.o ft_strcmp.o ft_write.o
