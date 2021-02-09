section .text
    global _ft_strcmp

_ft_strcmp:
    xor rcx, rcx
    xor rax, rax
    s_cmp:
        cmp BYTE [rdi + rcx], 0
        je end
        cmp BYTE [rsi + rcx], 0
        je end
        mov al, BYTE [rsi + rcx]
        cmp BYTE [rdi + rcx], al
        jne end
        inc rcx
        jmp s_cmp
    end:
        mov al, BYTE [rsi + rcx]
        cmp BYTE [rdi + rcx], al
        jg greater
        jl less
        mov rax, 0
        ret
    greater:
        mov rax, 1
        ret
    less:
        mov rax, -1
        ret