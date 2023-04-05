global _ft_list_sort

; void ft_list_sort(t_list **begin_list, int (*cmp)());

_ft_list_sort:
    enter 0, 0
    mov r12, [rdi]
_first_loop:
    cmp r12, 0
    je _end
    mov r13, [r12 + 8]
_second_loop:
    cmp r13, 0
    je _increment
    mov rdi, [r12]
    mov rsi, [r13]
    call [rdx]
    cmp rax, 0
    jg _swap
    mov r13, [r13 + 8]
    jmp _second_loop
_increment:
    mov r12, [r12 + 8]
    jmp _first_loop
_swap:
    enter 0, 0
    mov r12, [rdi]
    mov r13, [rdi + 8]
    mov [rdi], [r13]
    mov [r13], r12
    leave
    ret