global _ft_list_remove_if:

; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
_ft_list_remove_if:
    enter 0, 0
_skip: ; maybe it should be a dimension deeper (because of **)
    cmp rdi, 0
    je _end
    mov r12, rdi
    mov rdi, [rdi]
    call [rdx]
    mov rdi, r12
    cmp rax, 0
    jne _remove
    mov r12, [rdi + 8]
    call [rcx]
    mov rdi, r12
    jmp _skip
_remove:
    cmp qword [rdi + 8], 0
    je _end
    mov r12, [rdi + 8] ; now->next
    mov rdi, rdi + 8
    call [rcx]
    mov rdi, r12
    cmp rax, 0
    jne _remove
    mov r12, [rdi + 8] ; now->next->next
    mov rdi, [rdi] ; now->next
    call [rcx]
    mov rdi, r12
    jmp _remove
_end:
    leave
    ret
