section .text
    global _ft_list_remove_if
    extern _free

_ft_list_remove_if:
    push r12
    mov r12, [rdi]
    cmp rdi, 0
    je end
    cmp rdx, 0
    jz end
    cmp	rcx, 0
    jz end
    
    check_first_node:
        cmp rdi, 0
        je end
        mov r8, [rdi]
        push rdi
        mov rdi, [r8]
        call rdx
        cmp rax, 0
        jne check_other_nodes
        mov rdi, [r8 + 8]
        push rdi
        mov rdi, [r8]
        call rcx
        mov rdi, r8
        call _free
        pop rdi
    check_other_nodes:
        cmp r8, 0
        je end
        push rdi
        mov rdi, [r8]
        call rdx
        cmp rax, 0
        jne incr
        pop rdi
        mov r9, [r8 + 8]
        push rdi
        mov rdi, [r8]
        call rcx    
        mov rdi, r8
        call _free
        pop rdi
    incr:
        mov r8, [r8 + 8]
        jmp check_other_nodes
    end:
        mov rdi, [r12]
    restore:
        pop r12
        ret