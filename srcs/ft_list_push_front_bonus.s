section .text
    global _ft_list_push_front
    extern _malloc

_ft_list_push_front:
    push rsp
    push rdi
    push rsi
    mov rdi, 16
    call _malloc
    pop rsi
    pop rdi
    cmp rax, 0x0
    jz return
    mov QWORD [rax], rsi
    mov rcx, QWORD [rdi]
    mov QWORD [rax + 8], rcx
    mov QWORD [rdi], rax
    return:
        pop rsp
        ret
