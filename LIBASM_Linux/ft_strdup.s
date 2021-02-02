section .text
    global  ft_strdup
    extern malloc
    extern strlen
ft_strdup:
        call strlen
        push rdi
        mov rdi, rax
        call malloc
        pop rdi
        xor rcx, rcx
    dup:
        cmp BYTE [rdi + rcx], 0
        je end
        mov dl, BYTE [rdi + rcx]
        mov BYTE [rax + rcx], dl
        inc cl
        jmp dup
    end:
        mov BYTE [rax + rcx], 0
        ret