global _ft_strcmp

_ft_strcmp:
    cmp byte [rdi], 0
    je end
    cmp byte [rsi], 0
    je end
    cmp byte [rdi], byte [rsi]
    jne end
    inc rdi
    inc rsi
    jmp _ft_strcmp
end:
    mov rax, byte [rdi]
    sub rax, byte [rsi]
    ret