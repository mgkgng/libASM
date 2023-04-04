global _ft_strdup

extern _ft_strlen
extern _ft_strcpy
extern _malloc
extern ___error

_ft_strdup:
    enter 0, 0
    mov r12, rdi
    call _ft_strlen
    inc rax
    mov rdi, rax
    call _malloc
    cmp rax, 0
    je err
    mov rdi, rax
    mov rsi, r12
    call _ft_strcpy
done:
    leave
    ret
err:
    call ___error
    mov rdi, [rax]
    mov rax, 0
    jmp done