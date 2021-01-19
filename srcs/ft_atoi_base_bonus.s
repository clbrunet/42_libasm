BITS 64

					section	.text

					extern	ft_strlen

					static	ft_isspace
					static	get_index
					static	check_base_char
					static	check_base
					global	ft_atoi_base

; int	ft_isspace(rdi: int c);
ft_isspace:			enter	0, 0
					mov		rax, 0
					cmp		rdi, ' '
					je		.success_ret
					cmp		rdi, `\f`
					je		.success_ret
					cmp		rdi, `\n`
					je		.success_ret
					cmp		rdi, `\r`
					je		.success_ret
					cmp		rdi, `\t`
					je		.success_ret
					cmp		rdi, `\v`
					je		.success_ret

.fail_ret:			xor		rax, rax
					leave
					ret

.success_ret:		mov		rax, 1
					leave
					ret

; int	get_index(rdi: char c, rsi: char *str);
get_index:			enter	0, 0
					xor		rcx, rcx
					cld
					
.search_loop:		lodsb
					cmp		al, 0
					jz		.fail_ret
					movzx	rax, al
					cmp		rax, rdi
					je		.success_ret
					inc		rcx
					jmp		.search_loop

.success_ret:		mov		rax, rcx
					leave
					ret

.fail_ret:			mov		rax, -1
					leave
					ret

; char	check_base_char(rdi: char base_char, rsi: char *base);
check_base_char:	enter	0, 0
					cmp		rdi, '-'
					je		.error_ret
					cmp		rdi, '+'
					je		.error_ret
					push	rdi
					push	rsi
					call	ft_isspace
					pop		rsi
					pop		rdi
					cmp		rax, 1
					je		.error_ret
					call	get_index
					cmp		rax, -1
					jne		.error_ret

.success_ret:		mov		rax, 1
					leave
					ret

.error_ret:			xor		rax, rax
					leave
					ret

; char	check_base(rdi: char *base, rsi: int len);
check_base:			enter	0, 0
					cmp		rsi, 2
					jb		.error_ret
					mov		rsi, rdi
					cld

.while:				lodsb
					cmp		al, 0
					jz		.success_ret
					movzx	rdi, al
					push	rsi
					call	check_base_char
					pop		rsi
					cmp		rax, 0
					jz		.error_ret
					jmp		.while

.success_ret:		mov		rax, 1
					leave
					ret

.error_ret:			xor		rax, rax
					leave
					ret

; int	ft_atoi_base(rdi: char *str, rsi: char *base);
ft_atoi_base:		enter	40, 0
					xor		rax, rax
					mov		[rbp - 8], rax
					mov		[rbp - 16], rdi
					mov		[rbp - 24], rsi
					mov		rdi, rsi
					call	ft_strlen
					mov		[rbp - 32], rax
					mov		rdi, [rbp - 24]
					mov		rsi, rax
					call	check_base
					cmp		rax, 0
					jz		.ret
					mov		rsi, [rbp - 16]

.trim_whitespaces:	movzx	rdi, byte [rsi]
					push	rsi
					call	ft_isspace
					pop		rsi
					cmp		rax, 0
					je		.trim_signs_prep
					inc		rsi
					jmp		.trim_whitespaces
					
.trim_signs_prep:	xor		rcx, rcx

.trim_signs_loop:	movzx	rdi, byte [rsi]
					cmp		rdi, '-'
					je		.inc_minus_sign
					cmp		rdi, '+'
					je		.trim_signs_reloop
					jmp		.trim_signs_end

.inc_minus_sign:	inc		rcx

.trim_signs_reloop:	inc		rsi
					jmp		.trim_signs_loop

.trim_signs_end:	mov		[rbp - 40 ], rcx

.parse_number_loop:	movzx	rdi, byte [rsi]
					push	rsi
					push	rdi
					mov		rsi, [rbp - 24]
					call	get_index
					pop		rdi
					pop		rsi
					cmp		rax, -1
					jz		.ret
					mov		r10, rax
					mov		rax, [rbp - 8]
					imul	rax, [rbp - 32]
					add		rax, r10
					mov		[rbp - 8], rax
					inc		rsi
					jmp		.parse_number_loop

.ret:				mov		r10, [rbp - 40]
					and		r10, 1
					mov		rax, [rbp - 8]
					cmp		r10, 1
					je		.neg_result
					leave
					ret

.neg_result:		neg		rax
					leave
					ret
