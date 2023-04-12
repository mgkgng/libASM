global _ft_list_remove_if:

; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
_ft_list_remove_if:
    enter 16, 0
    push rdi
    mov rdi, [rdi]

    mov r12, rsi ; data_ref
    mov r13, rdx ; cmp_fct
    mov r14, rcx ; free_fct
_skip:
    cmp rdi, 0
    je _end
    mov r15, rdi
    mov rdi, [rdi]
    mov rsi, r12
    call r13 ; compare
    mov rdi, r15
    cmp rax, 0
    jne _keep_begin
    mov r15, [rdi + 8]
    call r14 ; free
    mov rdi, r15
    jmp _skip
_keep_begin:
    push rdi ; save begin
_remove:
    cmp qword [rdi + 8], 0
    je _end
    mov r15, rdi ; save now
    mov r8, [rdi + 8] ; now->next
    mov rdi, [r8] ; now->next->data
    mov rsi, r12
    call r13
    cmp rax, 0
    jne _back
    mov rdi, [r15 + 8] ; now->next
    mov rbx, [rdi + 8] ; save now->next->next
    call r14 ; free now->next
    mov rdi, r15
    mov [rdi + 8], rbx ; now->next = now->next->next
    mov rdi, rbx
    cmp rbx, 0
    je _end
    jmp _remove
_back:
    mov rdi, [r15 + 8] ; now->next
    jmp _remove
_end:
    pop rax ; begin
    pop rdi
    mov [rdi], rax ; *begin_list = begin
    leave
    ret
