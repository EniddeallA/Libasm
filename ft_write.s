section .text
    global ft_write

ft_write:
        push rsi
        cmp rsi, 0x0
        je _error
        mov rsi, 0x0
        mov rax, 5 ; fstat
        syscall
        cmp rax, -9
        je _error
        pop rsi
        mov rax, 1
        syscall
        ret
    _error:
        pop rsi
        mov rax, -1
        ret