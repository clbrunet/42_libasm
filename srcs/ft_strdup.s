BITS 64

			section	.text

			extern	malloc
			extern	ft_strlen
			extern	ft_strcpy

; char	*strdup(rdi: const char *s);
			global	ft_strdup

ft_strdup:	enter	8, 0
			mov		[rbp - 8], rdi
			call	ft_strlen
			mov		rdi, rax
			call	malloc
			cmp		rax, 0
			jz		.ret
			mov		rdi, rax
			mov		rsi, [rbp - 8]
			call	ft_strcpy

.ret:		leave
			ret
