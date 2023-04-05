global _ft_list_push_front
extern _malloc
extern ___error

; void ft_list_push_front(t_list **begin_list, void *data)

_ft_list_push_front:
    enter 0, 0
    mov r12, rdi
    mov rdi, 16
    call _malloc
    cmp rax, 0
    je err
    mov [rax], rsi
    mov qword [rax + 8], [rdi]
    mov qword [rdi], rax
end:
    leave
    ret
err:
    call ___error
    mov rdi, [rax]
    mov rax, 0
    jmp end