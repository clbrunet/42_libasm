BITS 64

			section	.text

			extern	ft_strlen

			global	ft_strcpy

; char	*ft_strcpy(rdi: char *dest, rsi: const char *src);
ft_strcpy:	enter	0, 0
			push	rdi
			push	rsi
			mov		rdi, rsi
			call	ft_strlen
			mov		rcx, rax
			inc		rcx
			pop		rsi
			pop		rax
			mov		rdi, rax
			cld
			rep		movsb
			leave
			ret
