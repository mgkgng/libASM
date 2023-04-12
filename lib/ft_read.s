global _ft_read:
extern ___error

_ft_read:
    enter 0, 0
    mov rax, 0x2000003
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