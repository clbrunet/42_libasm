BITS 64

					section	.text

					extern	ft_create_elem

; void	ft_list_push_front(rdi: t_list **begin_list, rsi: void *data);
					global	ft_list_push_front

ft_list_push_front:	enter	0, 0
					push	rdi
					mov		rdi, rsi
					call	ft_create_elem
					pop		rdi
					mov		r10, [rdi]
					mov		[rax + 8], r10
					mov		[rdi], rax
					leave
					ret
