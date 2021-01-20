BITS 64

					section	.text

					extern	ft_list_size

; void	ft_list_sort(rdi: t_list **begin_list, rsi: int (*cmp)());
					global	ft_list_sort

ft_list_sort:		enter	16, 0
					mov		[rbp - 8], rdi
					mov		[rbp - 16], rsi
					mov		rdi, [rdi]
					call	ft_list_size
					dec		rax
					xor		rcx, rcx

.sorting_loop:		cmp		rcx, rax
					jge		.ret
					push	rcx
					push	rax
					mov		r8, [rbp - 8]
					mov		r8, [r8]
					mov		r9, [r8 + 8]
					sub		rax, rcx
					xor		rcx, rcx

.swap_loop:			cmp		rcx, rax
					jge		.sorting_loop_end
					mov		rdx, [rbp - 16]
					push	rcx
					push	rax
					mov		rdi, [r8]
					mov		rsi, [r9]
					call	rdx
					pop		rax
					pop		rcx
					jle		.swap_loop_end

.swap:				mov		r10, [r8]
					mov		r11, [r9]
					mov		[r8], r11
					mov		[r9], r10

.swap_loop_end:		mov		r8, [r8 + 8]
					mov		r9, [r9 + 8]
					inc		rcx
					jmp		.swap_loop

.sorting_loop_end:	pop		rax
					pop		rcx
					inc		rcx
					jmp		.sorting_loop

.ret:				leave
					ret
