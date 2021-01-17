BITS 64

			section	.text

; size_t	ft_strlen(rdi: const char *s);
			global	ft_strlen

; repnz scasb version of ft_strlen
 ft_strlen:	enter	8, 0
 			mov		[rbp - 8], rdi
 			mov		rcx, -1
			xor		rax, rax
 			cld
 			repnz	scasb
 			dec		rdi
 			sub		rdi, [rbp - 8]
 			mov		rax, rdi
 			leave
 			ret

; scasb while loop version of ft_strlen
; ft_strlen:	enter	8, 0
; 			mov		[rbp - 8], rdi
; 			xor		rax, rax
;  			cld

; .while:		scasb
; 			jz		.end
; 			jmp		.while

; .end:		dec		rdi
; 			sub		rdi, [rbp - 8]
; 			mov		rax, rdi
; 			leave
; 			ret

; simple while loop version of ft_strlen
; ft_strlen:	enter	8, 0
; 			mov		[rbp - 8], rdi

; .while:		cmp		byte [rdi], 0
; 			jz		.end
; 			inc		rdi
; 			jmp		.while

; .end:		sub		rdi, [rbp - 8]
; 			mov		rax, rdi
; 			leave
; 			ret
