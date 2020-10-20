section	.text
global	_ft_write
extern	___error

_ft_write:			    					; ssize_t ft_write(int fd(rdi), void *buf(rsi), size_t count(rdx));
            cmp         rsi, 0				; if buf == NULL --> error
            jz          error
			push		rdx
            mov         rax, 0x2000004		; number of func (for syscall)
            syscall							;
            jc			error_write
			pop			rdx
			mov			rax, rdx
			ret
error:
            mov     rax, -1					; rax - return value
            ret
error_write:
			call		___error
			mov		rax, -1
			ret