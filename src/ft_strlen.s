section .text
    global _ft_strlen

_ft_strlen:
    enter 0, 0
    mov rbp, rsp
    xor rax, rax
loop:
    cmp byte [rdi + rax], 0
    je end
    inc rax
    jmp loop
end:
    leave
    ret