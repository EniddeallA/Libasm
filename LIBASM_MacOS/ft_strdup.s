section .text
    global _ft_strdup
    extern _malloc
    extern _ft_strlen
    extern ___error
    extern _ft_strcpy

_ft_strdup:
    cmp rdi, 0x0
    je error
    call _ft_strlen
    push rdi
    mov rdi, rax
    call _malloc
    cmp rax, 0
    je error
    pop rdi
    mov rsi, rdi
    mov rdi, rax
    call _ft_strcpy
    ret
    error:
        call ___error
        mov [rax], BYTE 12
        mov rax, 0
        ret