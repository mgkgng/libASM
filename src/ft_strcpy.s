section .text
    global _ft_strcpy

_ft_strcpy:
    xor rax, rax
    
loop:
    cmp byte [rdi + rax], 0
    je done
    mov cl, byte [rdi + rax]
    mov byte [rsi + rax], cl
    inc rax
    jmp loop
end:
    mov byte [rdi + rax], 0
    mov rax, rdi