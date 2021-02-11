section .text
    global _ft_list_sort

_ft_list_sort:
    mov rdx, [rdi]
    mov r9, [rdi]
    iterate_prev:
        cmp rdx, 0
        je end
        mov rcx, [rdx + 8]
        iterate_next:
                cmp rcx, 0
                je end
                push rdi
                push rsi
                mov rdi, [rdx]
                mov rsi, [rcx]
                call rsi
                pop rsi
                pop rdi
                cmp rax, 1
                je sort
            back:
                mov rcx, [rdx + 8]
                jmp iterate_next
        mov rdx, [rdx + 8]
        jmp iterate_prev
    sort:
        mov r8, [rdi]
        mov rdx,  [r8]
        mov rax, [rcx]
        mov [r8], rax
        mov [rcx], rdx
        jmp back

    end:
        mov [rdi], r9
        ret
    