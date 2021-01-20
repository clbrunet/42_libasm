BITS 64

					section	.text

					extern	free

; void	ft_list_remove_if(rdi: t_list **begin_list, rsi: void *data_ref, rdx: int (*cmp)(), rcx: void (*free_fct)(void *));
					global	ft_list_remove_if

ft_list_remove_if:	enter	32, 0
					cmp		rdi, 0
					jz		.ret
					cmp		rdi, 0
					jz		.ret
					cmp		rsi, 0
					jz		.ret
					cmp		rdx, 0
					jz		.ret
					cmp		rcx, 0
					jz		.ret
					mov		[rbp - 8], rdi
					mov		[rbp - 16], rsi
					mov		[rbp - 24], rdx
					mov		[rbp - 32], rcx
					mov		rdi, [rdi]

.remove_firsts_loop:cmp		rdi, 0
					jz		.ret
					push	rdi
					mov		rdi, [rdi]
					mov		rsi, [rbp - 16]
					call	[rbp - 24]
					pop		rdi
					cmp		rax, 0
					jnz		.remove_elems_loop
					push	rdi
					mov		rdi, [rdi]
					call	[rbp - 32]
					pop		rdi
					mov		r10, [rbp - 8]
					mov		r11, [rdi + 8]
					mov		[r10], r11
					push	r11
					call	free
					pop		rdi
					jmp		.remove_firsts_loop

.remove_elems_loop:	mov		rsi, [rdi + 8]
					cmp		rsi, 0
					jz		.ret
					push	rdi
					push	rsi
					mov		rdi, [rsi]
					mov		rsi, [rbp - 16]
					call	[rbp - 24]
					pop		rsi
					pop		rdi
					cmp		rax, 0
					cmovnz	rdi, [rdi + 8]
					jnz		.remove_elems_loop
					push	rdi
					push	rsi
					mov		rdi, [rsi]
					call	[rbp - 32]
					pop		rsi
					pop		rdi
					mov		r10, [rsi + 8]
					mov		[rdi + 8], r10
					push	rdi
					mov		rdi, rsi
					call	free
					pop		rdi
					jmp		.remove_elems_loop

.ret:				leave
					ret
