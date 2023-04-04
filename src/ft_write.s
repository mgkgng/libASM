global _ft_write
extern ___error

_ft_write:
    enter 0, 0
    mov rax, 0x2000004
    syscall
    cmp rax, -1
    je err
done:
    leave
    ret
err:
    call ___error
    mov rdi, [rax]
    mov rax, -1
    jmp done