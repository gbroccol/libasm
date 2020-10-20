global	_ft_strcpy
section	.text

_ft_strcpy:										; char	*ft_strcpy(char *dest(rdi),const char *src(rsi))
			xor			rcx, rcx				; i = 0
			cmp			rdi, 0x0				; if (!dest) -> error
			jz			error
			cmp			rsi, 0x0				; if (!src) -> return
			jz			return
			jmp			while
while:
			mov			dl, byte [rsi + rcx]	; dl = rsi[rcx]
			mov			byte[rdi + rcx], dl		; rdi[rcx] = dl
			cmp			dl, 0x0					; if s2[i] == \0 --> return
			jz			return
			inc			rcx						; rcx++
			jmp			while
error:
			xor			rax, rax				; rax = 0
			ret
return:
			lea			rax, [rdi]
			ret
