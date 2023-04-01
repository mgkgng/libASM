global _ft_strcmp

_ft_strcmp:
    enter 0, 0
    xor rcx, rcx
loop:
    cmp byte [rdi + rcx], 0
    je end
    cmp byte [rsi + rcx], 0
    je end
    mov al, byte [rdi + rcx]
    cmp al, byte [rsi + rcx]
    jne end
    inc rcx
    jmp loop
end:
    movzx rax, byte [rdi + rcx]
    movzx rdx, byte [rsi + rcx]
    sub rax, rdx
    leave
    ret