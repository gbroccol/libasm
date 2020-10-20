section .text
global	_ft_strdup
extern	_malloc
extern	_ft_strcpy
extern	_ft_strlen

_ft_strdup:                             ; char *_ft_strdup(const char *str(rdi));
           xor			rax, rax
		   cmp         rdi, 0x0        ; if str == NULL --> error
           jz          error
           call        _ft_strlen      ; count str's len(rax)
           inc         rax             ; rax++
           push        rdi             ; push str(rdi) to stack 
           mov         rdi, rax        ; rdi = (str_len + 1) - the 1st argument for malloc
           call        _malloc
           cmp         rax, 0x0        ; if rax == NULL --> error
           jz          error
           pop         rdi             ; take rdi from stack
		   mov			rsi, rdi
		   mov			rdi, rax
           call        _ft_strcpy      ; rdi(1st arg. - dest), rsi(2nd arg. - src)
           ret
error:
           mov     rax, 0x0            ; return NULL
           ret
