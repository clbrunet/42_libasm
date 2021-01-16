BITS 64

			section	.text

			global	ft_strlen

; size_t	ft_strlen(rdi: const char *s);
ft_strlen:	enter	0, 0
			mov		r10, rdi
			mov		rcx, -1
			mov		rax, 0
			cld
			repnz	scasb
			dec		rdi
			sub		rdi, r10
			mov		rax, rdi
			leave
			ret
