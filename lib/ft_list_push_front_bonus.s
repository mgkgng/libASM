global _ft_list_push_front
extern _malloc
extern ___error

;typedef struct s_list {
;	void			*data;
;	struct s_list	*next;
;} t_list;

; void ft_list_push_front(t_list **begin_list, void *data)

_ft_list_push_front:
    enter 8, 0
    mov r12, [rdi]
    mov r13, rsi
    push rdi
    mov rdi, 0x10
    call _malloc
    cmp rax, 0
    je err
    pop rdi
    mov [rax], r13
    mov [rax + 8], r12
    mov [rdi], rax
end:
    leave
    ret
err:
    call ___error
    mov rdi, [rax]
    mov rax, 0
    jmp end