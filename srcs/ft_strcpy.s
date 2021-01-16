BITS 64

			section	.text

			extern	ft_strlen

; char	*ft_strcpy(rdi: char *dest, rsi: const char *src);
			global	ft_strcpy

; rep movsb version of ft_strcpy

ft_strcpy:	enter	16, 0
			mov		[rbp - 8], rdi
			mov		[rbp - 16], rsi
			mov		rdi, rsi
			call	ft_strlen
			mov		rcx, rax
			inc		rcx
			mov		rdi, [rbp - 8]
			mov		rsi, [rbp - 16]
			cld
			rep		movsb
			mov		rax, [rbp - 8]
			leave
			ret

; lodsb and stosb while loop version of ft_strcpy

; ft_strcpy:	enter	8, 0
; 			mov		[rbp - 8], rdi
; 			cld

; .while:		lodsb
; 			cmp		al, 0
; 			je		.end
; 			stosb
; 			jmp		.while

; .end:		mov		byte [rdi], 0
; 			mov		rax, [rbp - 8]
; 			leave
; 			ret

; simple while loop version of ft_strcpy

; ft_strcpy:	enter	0, 0
; 			mov		rax, rdi

; .while:		cmp		byte [rsi], 0
; 			je		.end
; 			mov		r10b, byte [rsi]
; 			mov		byte [rdi], r10b
; 			inc		rdi
; 			inc		rsi
; 			jmp		.while

; .end:		mov		byte [rdi], 0
; 			leave
; 			ret
