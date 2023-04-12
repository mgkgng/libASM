global _ft_list_sort

; void ft_list_sort(t_list **begin_list, int (*cmp)());

_ft_list_sort:
    enter 8, 0
    mov r12, [rdi]
    push rdi
    mov rdx, rsi ; rdx = cmp function
_first_loop:
    cmp r12, 0
    je _end
    mov r13, [r12 + 8]
_second_loop:
    cmp r13, 0
    je _increment
    mov rdi, [r12]
    mov rsi, [r13]
    call rdx
    cmp rax, 0
    jle _next
    mov rbx, [r12] ; rbx = r12->data
    mov rcx, [r13] ; rcx = r13->data
    mov [r12], rcx
    mov [r13], rbx
    mov r13, [r13 + 8] ; increment
    jmp _second_loop
_increment:
    mov r12, [r12 + 8]
    jmp _first_loop
_next:
    mov r13, [r13 + 8]
    jmp _second_loop
_end:
    pop rdi
    leave
    ret