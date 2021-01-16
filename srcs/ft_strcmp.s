BITS 64

			section	.text

			extern	ft_strlen

; int	ft_strcmp(rdi: const char *s1, rsi: const char *s2);
			global	ft_strcmp

; repe cmpsb version of ft_strcmp

ft_strcmp:	enter	24, 0
			mov		[rbp - 8], rdi
			mov		[rbp - 16], rsi
			call	ft_strlen
			mov		rdi, [rbp - 16]
			mov		[rbp - 24], rax
			call	ft_strlen
			cmp		rax, [rbp - 24]
			cmovb	rcx, rax
			cmovnb	rcx, [rbp - 24]
			mov		rdi, [rbp - 8]
			mov		rsi, [rbp - 16]
			cld
			repe	cmpsb
			dec		rdi
			dec		rsi
			mov		rax, [rdi]
			sub		rax, [rsi]
			leave
			ret

; lodsb while loop version of ft_strcmp

; ft_strcmp:	enter	0, 0
; 			cld

; .while:		lodsb
; 			cmp		al, byte [rdi]
; 			jne		.end
; 			cmp		al, 0
; 			je		.end
; 			inc		rdi
; 			jmp		.while

; .end:		movzx	rax, al
; 			movzx	r10, byte [rdi]
; 			sub		rax, r10
; 			neg		rax
; 			leave
; 			ret

; simple while loop version of ft_strcmp

; ft_strcmp:	enter	0, 0

; .while:		mov		al, byte [rdi]
; 			cmp		al, byte [rsi]
; 			jne		.end
; 			cmp		al, 0
; 			je		.end
; 			inc		rdi
; 			inc		rsi
; 			jmp		.while

; .end:		movzx	rax, al
; 			movzx	r10, byte [rsi]
; 			sub		rax, r10
; 			leave
; 			ret
