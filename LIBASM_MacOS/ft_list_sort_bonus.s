section .text
    global _ft_list_sort

_ft_list_sort:
    push r9
    push r12
    cmp rdi, 0
    je restore
    mov r12, [rdi]
    cmp rsi, 0
    jz end
    jmp compare_begin
    incr_begin:
        mov r8, [rdi]
        mov r9, [r8 + 8]
        mov [rdi], r9
    compare_begin:
        cmp QWORD [rdi], 0
        jz end
        mov r8, [rdi]
        mov r9, [r8 + 8]
    compare_current:
        cmp r9, 0
        jz incr_begin
    sort:
        push rdi
        push rsi
        mov rax, rsi
        mov rdi, [r8]
        mov rsi, [r9]
        call rax
        pop rsi
        pop rdi
        cmp rax, 0
        jg swap
    incr_current:
        mov r8, [r9 + 8]
        mov r9, r8
        jmp compare_current
    swap:
        mov rcx, [rdi]
        mov r8, [rcx]
        mov rax, [r9]
        mov [rcx], rax
        mov [r9], r8
        jmp incr_current
    end:
        mov [rdi], r12
    restore:
        pop r12
        pop r9
        ret