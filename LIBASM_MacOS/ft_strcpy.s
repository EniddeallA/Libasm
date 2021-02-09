section .text
    global _ft_strcpy

_ft_strcpy:
    xor rcx, rcx
    xor rax, rax
    copy:
        cmp BYTE [rsi + rcx], 0x0
        je end
        mov al, BYTE [rsi + rcx]
        mov BYTE [rdi + rcx], al
        inc rcx
        jmp copy
    end:
        mov BYTE [rdi + rcx], 0x0
        mov rax, rdi
        ret