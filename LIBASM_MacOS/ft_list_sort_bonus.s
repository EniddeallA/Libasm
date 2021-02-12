section .text
    global _ft_list_sort

_ft_list_sort:
    cmp rdi, 0
    je end
    mov r8, [rdi]
    prev:
        cmp r8, 0
        je end
        mov r9, [r8 + 8]
        next:
            cmp r9, 0
            je prev_iter
            mov rdx, [rsi]
            push rdi
            pop rsi
            call rdx
            pop rsi
            pop rdi
            cmp rax, 1
            je sort
        next_iter:
            mov r9, [r9 + 8]
            jmp next
    prev_iter:
        mov r8, [r8 + 8]
        jmp prev

    sort:
        mov r10, [r8]
        mov r11, [r9]
        mov r9, r10
        mov r8, r10
        jmp next_iter
    end:
        ret