global _ft_atoi_base

; int ft_atoi_base(char *str, char *base)
_ft_atoi_base:
    enter 8, 0
    push rdi
    mov rdi, rsi
    call _check_base
    pop rdi
    cmp rax, 0
    jle _end_error
    xor r12, r12 ; r12 = result
    xor r13, r13 ; r13 = sign (0 = positive, 1 = negative)
    mov r14, rax ; r14 = base_len, r15 = base_index
_first_loop:
    cmp byte [rdi], 0
    je _end
    call _is_space
    cmp rax, 0
    je _space
    cmp byte [rdi], 0x2d
    je _negative
    cmp byte [rdi], 0x2b
    je _positive
    jmp _second_loop
_space:
    inc rdi
    jmp _first_loop
_negative:
    inc rdi
    xor r13, 1
    jmp _first_loop
_positive:
    inc rdi
    jmp _first_loop
_second_loop:
    cmp byte [rdi], 0
    je _end
    call _is_in_base ; r14 = base_len, r15 = base_index
    cmp rax, r14 ; if the character is not included in the base
    je _end
    mov r15, rax
    mov rax, r12
    mul r14
    add rax, r15
    mov r12, rax
    inc rdi
    jmp _second_loop
_end:
    mov rax, r12
    cmp r13, 1
    je _negative_end
    jmp _end_end
_negative_end:
    neg rax
_end_end:
    leave
    ret
_end_error:
    mov rax, 0
    leave
    ret

_check_base:
    enter 16, 0
    xor rax, rax
    xor rcx, rcx
    push rdi
    push rsi
_check_base_loop:
    cmp byte [rdi], 0
    je _check_base_end
    cmp byte [rdi], 0x2b ; check +
    je _check_base_end_false
    cmp byte [rdi], 0x2d ; check -
    je _check_base_end_false
    call _is_space ; check whitespace
    cmp rax, 0
    je _check_base_end_false
    call _is_duplicate
    cmp rax, 0
    je _check_base_end_false
    inc rdi
    inc rcx
    jmp _check_base_loop
_check_base_end:
    cmp rcx, 1
    jle _check_base_end_false
    mov rax, rcx
    pop rdi
    pop rsi
    leave
    ret
_check_base_end_false:
    pop rdi
    leave
    ret

_is_space:
    enter 0, 0
    mov rax, 0
    cmp byte [rdi], 0x20
    je _is_space_end
    mov rax, 1
    cmp byte [rdi], 0x09
    jl _is_space_end
    cmp byte [rdi], 0x0d
    jg _is_space_end
    mov rax, 0
_is_space_end:
    leave
    ret

_is_duplicate:
    enter 0, 0
    movzx r12, byte [rdi]
    mov rsi, rdi
    inc rsi
_is_duplicate_loop:
    cmp byte [rsi], 0
    je _no_duplicate
    cmp r12b, byte [rsi]
    je _with_duplicate
    inc rsi
    jmp _is_duplicate_loop
_no_duplicate:
    mov rax, 1
    leave
    ret
_with_duplicate:
    mov rax, 0
    leave
    ret

_is_digit:
    enter 0, 0
    mov rax, 0
    cmp byte [rdi], 0x30
    jl _is_digit_end
    cmp byte [rdi], 0x39
    jg _is_digit_end
    mov rax, 1
_is_digit_end:
    leave
    ret

_is_in_base:
    enter 0, 0
    xor rax, rax
    movzx r8, byte [rdi] ; r8 = current character
_is_in_base_loop:
    movzx rcx, byte [rsi + rax] ; rcx = current character in the base string
    cmp rcx, 0
    je _is_in_base_end
    cmp r8, rcx
    je _is_in_base_end
    inc rax
    jmp _is_in_base_loop
_is_in_base_end:
    leave
    ret