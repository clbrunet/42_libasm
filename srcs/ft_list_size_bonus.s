BITS 64

				section	.text

; int	ft_list_size(rdi: t_list *begin_list);
				global	ft_list_size

ft_list_size:	enter	0, 0
				xor		rcx, rcx

.loop:			cmp		rdi, 0
				jz		.ret
				mov		rdi, [rdi + 8]
				inc		rcx
				jmp		.loop

.ret:			mov		rax, rcx
				leave
				ret
