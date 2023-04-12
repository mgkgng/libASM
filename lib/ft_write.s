global _ft_write
extern ___error

_ft_write:
    enter 0, 0
    mov rax, 0x2000004
    syscall
    jc err
done:
    leave
    ret
err:
    mov rdx, rax
    call ___error
    mov [rax], rdx
    mov rax, -1
    jmp done