BITS 64

				section	.text

				extern	malloc

; t_list	*ft_create_elem(rdi: void *data);
				global	ft_create_elem

ft_create_elem:	enter	0, 0
				push	rdi
				mov		rdi, 16
				call	malloc
				pop		rdi
				mov		[rax], rdi
				leave
				ret
