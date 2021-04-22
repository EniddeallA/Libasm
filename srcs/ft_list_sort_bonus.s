section	.text
	global	_ft_list_sort

_ft_list_sort:
	mov rdx, [rdi]
	mov r8, rsi

current:
	cmp rdx, 0
	je exit
	mov rcx, qword [rdx+8]
	jmp next

next:
	cmp rcx, 0
	je incr_current
	mov rdi, qword [rdx]
	mov rsi, qword [rcx]
	push rdx
	push rcx
	push r8
	call r8
	pop r8
	pop rcx
	pop rdx
	cmp rax, 0
	jg sort
	mov rcx, qword [rcx+8]
	jmp next

sort:
	mov rdi, qword [rdx]
	mov rsi, qword [rcx]
	mov qword [rdx], rsi
	mov qword [rcx], rdi
	mov rcx, qword [rcx+8]
	jmp next


incr_current:
	mov rdx, qword [rdx+8]
	jmp current

exit:
	ret
