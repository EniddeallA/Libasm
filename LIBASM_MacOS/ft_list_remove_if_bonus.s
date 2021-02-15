section .text
    global _ft_list_remove_if
    extern _free

_ft_list_remove_if:
    push rbp
    push rbx
    push r12
    mov r12, [rdi]
    cmp rdi, 0
    je end
    cmp rdx, 0
    jz end
    cmp	rcx, 0
    jz end
    jmp compare  
    
    compare:
        cmp QWORD [rdi], 0
        je end
        push rdi
        push rsi
        push rdx
        push rcx
        mov r8, [rdi]
        mov rdi, [r8]
        call rdx
        pop rcx
        pop rdx
        pop rsi
        pop rdi
        cmp rax, 0
        je my_free
        mov rbx, [rdi]
        mov r8, [rbx + 8]
        mov [rdi], r8
        jmp compare

    my_free:
        mov r8, [rdi]
        mov rbp, [r8 + 8]
        push rsi
        push rdx
        push rcx
        push rdi
        mov rdx, [rdi]
        mov rdi, [rdx]
        call rcx
        pop rdi
        push rdi
        mov rdx, [rdi]
        mov rdi, rdx
        call _free
        pop rdi
        pop rcx
        pop rdx
        pop rsi
        mov [rdi], rbp
        cmp rbx, 0
        jne decr
        mov r12, rbp
        jmp compare
    
    decr:
        mov [rbx + 8], rbp
        jmp compare

    end:
        mov [rdi], r12
        pop r12
        pop rbx 
        pop rbp
        ret