section .text
    global ft_strcmp

ft_strcmp:
        xor rcx,rcx
        xor rax, rax
        xor rdx, rdx
    compare:
        cmp BYTE[rsi + rcx], 0
        je end
        cmp BYTE[rdi + rcx], 0
        je end
        mov al, BYTE [rdi + rcx]
        mov dl, BYTE [rsi + rcx]
        cmp al, dl
        jne end
        inc rcx
        jmp compare
    end:
        mov al, BYTE [rdi + rcx]
        mov dl, BYTE [rsi + rcx]
        cmp al, dl
        jg great
        jl less
        mov rax, 0
        ret
    great:
        mov rax, 1
        ret
    less:
        mov rax, -1
        ret