section .text
    global _ft_atoi_base
    extern _ft_strlen

_ft_atoi_base:
    push rbx
    push rdi
    mov rdi, rsi
    call _ft_strlen
    pop rdi
    cmp rax, 1
    jle error
    mov r9, rax
    xor rcx, rcx
    xor rdx, rdx
    xor r11, r11
    atoi_base:
        cmp BYTE [rdi + r11], 0x0
        je end
        check_str:
            mov dl, BYTE [rdi + r11]
            mov dh, BYTE [rsi + rcx]
            cmp dl, dh
            je atoi
            cmp BYTE [rsi + rcx], 0x0
            je atoi
            inc rcx
            jmp check_str
        atoi:
            cmp BYTE [rsi + rcx], 0x0
            je error
            call _ft_strlen
            mov r8, rax
            sub r8, r11
            sub r8, 1
            mov rax, 1
            xor r10, r10
            power:
                cmp r10, r8
                jge back
                mul r9
                inc r10
                jmp power
        back:
            mul rcx
            add rbx, rax
            inc r11
            jmp atoi_base
    end:
        cmp r11, 0
        je error
        mov rax, rbx
        pop rbx
        ret
    error:
        mov rax, 0
        pop rbx
        ret