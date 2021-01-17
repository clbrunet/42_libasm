BITS 64

			section	.text

			extern	__errno_location

; ssize_t	ft_write(rdi: int fd, rsi: const void *buf, rdx: size_t count);
			global	ft_write

ft_write:	enter	8, 0
			mov		rax, 1
			syscall
			cmp		rax, 0
			jge		.end

.error:		neg		rax
			mov		[rbp - 8], rax
			call	__errno_location
			mov		r10, [rbp - 8]
			mov		[rax], r10
			mov		rax, -1

.end:		leave
			ret
