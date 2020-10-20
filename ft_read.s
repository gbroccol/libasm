section	.text
global	_ft_read
extern	___error

_ft_read:			    					; ssize_t ft_read(int fd(rdi), void *buf(rsi), size_t count(rdx));
			cmp			rsi, 0				; if buf == NULL --> error
			jz          error
			mov         rax, 0x2000003		; number of func (for syscall)
			syscall							;
			jc			error_read
			ret
error:
			mov     rax, -1					; rax - return value
			ret
error_read:
			call		___error
			mov		rax, -1
			ret