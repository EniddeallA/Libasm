section .text
    global _ft_atoi_base
    extern _ft_strlen

_ft_atoi_base:
	xor rcx, rcx
	xor rdx, rdx
	xor r8, r8
	xor r9, r9
	mov r10, 1
	xor r11, r11
	push r12
	mov r12, 0

	cmp rdi, 0x0
	jz error
	cmp rsi, 0x0
	jz error
	push rdi
	mov rdi, rsi
	call _ft_strlen
	pop rdi
	cmp rax, 2
	jl error
	mov r8, rax
check_spaces:
	mov r11, 1
	cmp BYTE [rdi + rcx], 32
	je incr_rcx
	cmp BYTE [rdi + rcx], 9
	je incr_rcx
	cmp BYTE [rdi + rcx], 11
	je incr_rcx
	jmp check_sign
incr_rcx:
	inc rcx
	cmp r11, 1
	je check_spaces
	cmp r11, 2
	inc r12
	je check_sign
check_sign:
	mov r11, 2
	cmp BYTE [rdi + rcx], 43
	je incr_rcx
	cmp BYTE [rdi + rcx], 45
	je negative
	jmp atoi_rdi
negative:
	inc r12
	mov r10, -1
	inc rcx
	jmp check_sign
atoi_rdi:
	cmp r12, 1
	jg error
	cmp BYTE [rdi + rcx], 0x0
	je end_atoi
atoi_rsi:
	cmp BYTE [rsi + rdx], 0x0
	je end_atoi
	xor r11, r11
	mov r11b, [rdi + rcx]
	mov al, [rsi + rdx]
	cmp r11b, al
	je calculate
	inc rdx
	jmp atoi_rsi
calculate:
	imul r9, r8
	add r9, rdx
	inc rcx
	mov rdx, 0
	jmp atoi_rdi
end_atoi:
	mov rax, r9
	mul r10
end:
	pop r12
	ret

error:
	pop r12
	mov rax, 0
	ret