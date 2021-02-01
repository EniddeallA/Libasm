section .text
    global ft_strcpy

ft_strcpy:
        mov rdx, 0
    copy:
        cmp BYTE [rsi + rdx], 0
        je end
        mov al, BYTE [rsi + rdx]
        mov BYTE [rdi + rdx], al
        inc rdx
        jmp copy
    end:
        xor al, al
        mov BYTE [rdi + rdx], al
        mov rax, rdi
        ret