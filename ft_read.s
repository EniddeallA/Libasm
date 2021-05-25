section .text
    global _ft_read
    extern ___error
    
_ft_read:
    mov rax, 0x2000003
    syscall
    jc error
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