section .text
    global ft_read

ft_read:
        mov rax, 0
        syscall
        cmp rax, -14
        je _error
        ret
    _error:
        mov rax, -1
        ret