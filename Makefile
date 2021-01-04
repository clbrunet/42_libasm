all:
	make -C ./42_libft/
	clang -c ft_strcpy.c -g3 -fsanitize=address
	clang -c ft_strcmp.c -g3 -fsanitize=address
	clang -c ft_write.c -g3 -fsanitize=address
	clang -c ft_read.c -g3 -fsanitize=address
	clang -c ft_atoi_base.c -g3 -fsanitize=address
	clang -c ft_list_size.c -g3 -fsanitize=address
	clang -c ft_list_push_front.c -g3 -fsanitize=address
	cp ./42_libft/libft.a ./libasm.a
	ar -rcs libasm.a ft_strcpy.o ft_write.o ft_read.o ft_atoi_base.o ft_list_size.o ft_list_push_front.o
