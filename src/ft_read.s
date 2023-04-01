global _ft_read:

_ft_read:
    enter 0, 0
    mov rax, 0x2000003
    syscall
    cmp rax, -1
    jne done
done:
    leave
    ret