global _ft_strcpy

_ft_strcpy:
    enter 0, 0
    xor rcx, rcx
loop:
    cmp byte [rsi + rcx], 0
    je end
    mov dl, byte [rsi + rcx]
    mov byte [rdi + rcx], dl
    inc rcx
    jmp loop
end:
    mov byte [rdi + rcx], 0
    mov rax, rdi
    leave
    ret