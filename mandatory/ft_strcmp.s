section .text
    global _ft_strcmp

_ft_strcmp:
	mov cl, BYTE [rdi]
	mov dl, BYTE [rsi]
	cmp cl, 0
	je end
	cmp dl, 0
	je end
	cmp cl, dl
	jne end
	inc rdi
	inc rsi
	jmp _ft_strcmp

end:
	movzx rax, cl
	movzx rbx, dl
	sub rax, rbx
    cmp rax, 0
    jg greater
    jl less
    ret
    greater:
        mov rax, 1
        ret
    less:
        mov rax, -1
	    ret