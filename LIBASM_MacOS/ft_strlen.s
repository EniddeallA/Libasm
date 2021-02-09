section .text
    global _ft_strlen
_ft_strlen:
    xor rax, rax
    len:
        cmp BYTE[rdi + rax], 0x0
        je end
        inc rax
        jmp len
    end:
        ret