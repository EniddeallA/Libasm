section .text
    global  ft_strlen

ft_strlen:
        xor rax, rax
    length:
        cmp BYTE [rdi + rax], 0
        jz end
        inc rax
        jmp length
    end:
        ret