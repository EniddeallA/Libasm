section .data
    msg db "hello world",0
section .text
    global  ft_strlen

ft_strlen:
    xor rax, rax
    loop:
        cmp BYTE [rdi + rax], 0
        jz end
        inc rax
        jmp loop
    end:
        ret