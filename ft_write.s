section .text
    global _ft_write
    extern ___error

_ft_write:
    cmp rdx, 0
    jl len_error
    mov rax, 0x2000004
    syscall
    jc error
    ret
    len_error:
        mov rax, -1
        ret
    error:
        cmp rax, 9
        je bad_fd
        cmp rax, 14
        je bad_address
    bad_address:
        push rbp
        mov rbp, rsp
        call ___error
        mov QWORD [rax], 14
        mov rax, -1
        mov rsp, rbp
        pop rbp
        ret
    bad_fd:
        push rbp
        mov rbp, rsp
        call ___error
        mov QWORD [rax], 9
        mov rax, -1
        mov rsp, rbp
        pop rbp
        ret