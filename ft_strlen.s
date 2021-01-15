section .data
    msg db "hello world",0
section .text
    global  _start

_start:
    mov rdi, msg
    call ft_strlen
    int 80h
    ret

ft_strlen:
    xor rcx, rcx
    loop:
        cmp byte [rdi], 0x0
        jz end
        inc rcx
        inc rdi
        jmp loop
    end:
        mov rax, rcx
        ret