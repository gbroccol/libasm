global	_ft_strcmp
section	.text

_ft_strcmp:										; int	ft_strcmp(const char *s1(rdi), const char *s2(rsi));
			cmp		rdi, 0x0
			jz		return_zero
			cmp		rsi, 0x0
			jz		return_zero
			mov		rcx, 0x0
while:
			mov		dh, byte[rdi + rcx]
			mov		dl, byte[rsi + rcx]
			cmp		dh, dl
			jz		check_finish				; if s1[i] == s2[i] --> check_finish
			jmp		cmp_rdi_rsi					; if s1[i] != s2[i] --> cmp_rdi_rsi

check_finish:
			cmp		dl, 0x0						; s1[i] == '\0' ? --> return(0) 
			jz		return_zero
			inc		rcx							; rcx++
			jmp		while						; --> while

cmp_rdi_rsi:
			js		return_less
			jns		return_more
return_less:
			mov		rax, -1	
			ret
return_more:
			mov		rax, 0x1
			ret
return_zero:
			mov		rax, 0x0
			ret