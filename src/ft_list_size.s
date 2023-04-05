global _ft_list_size

; int ft_list_size(t_list *begin_list);

_ft_list_size:
    enter 0, 0
    xor rax, rax
loop:
    test rdi, rdi
    je end
    inc rax
    mov rdi, [rdi + 8]
    jmp loop
end:
    leave
    ret