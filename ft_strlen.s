global	_ft_strlen
section	.text

_ft_strlen:											; size_t _ft_strlen(const char *str(rdi));
			xor		rax, rax						; rax = 0
while:
			cmp		byte [rdi + rax], 0x0			; s[i] == 0 ?
			jz		return							; if TRUE --> return(rax);
			inc		rax								; rax++
			jmp		while							; again
return:
			ret
