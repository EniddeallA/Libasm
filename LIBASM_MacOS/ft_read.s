section .text
    global _ft_read

_ft_read:
    mov rax, 0x20000003
    syscall
    ret