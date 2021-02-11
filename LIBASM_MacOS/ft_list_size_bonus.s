section .text
    global _ft_list_size

_ft_list_size:
    xor rdx, rdx
    iterate:
        cmp rdi, 0
        je end
        mov rdi, [rdi + 8]
        inc rdx
        jmp iterate
    end:
        mov rax, rdx
        ret