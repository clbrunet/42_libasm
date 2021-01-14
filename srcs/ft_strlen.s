BITS 64

			section	.text

			global	ft_strlen

ft_strlen:	enter	0, 0
			cld
			mov		rcx, -1
			mov		rax, 0
			repnz	scasb
			add		rcx, 2
			neg		rcx
			mov		rax, rcx
			leave
			ret
