global _ft_atoi_base

_ft_atoi_base:
    enter 0, 0
    mov r12, 0 ; r12 = result
    mov r13, 0 ; r13 = sign (0 = positive, 1 = negative)
    mov r14, 0 ; r14 = base
    mov r15, 0 ; r15 = base_len



_first_loop:
    call _is_space
    cmp rax, 1
    je _space
    cmp byte [rdi], 0x2d
    je _negative
    cmp byte [rdi], 0x2b
    je _positive
    jmp _second_loop

_second_loop:
    call _is_digit
    cmp rax, 1
    je _digit
    jmp _end

_end:
    mov rax, r13
    cmp r12, 1
    je _negative_end
    jmp _end_end
_negative_end:
    neg rax
_end_end:
    leave
    ret

_space:
    inc rdi
    jmp _first_loop
_negative:
    inc rdi
    inc r13
    jmp _first_loop
_positive:
    inc rdi
    dec r13
    jmp _second_loop

_is_space:
    enter 0, 0
    mov rax, 1
    cmp byte [rdi], 0x09
    je _is_space_end
    cmp byte [rdi], 0x0a
    je _is_space_end
    cmp byte [rdi], 0x0b
    je _is_space_end
    cmp byte [rdi], 0x0c
    je _is_space_end
    cmp byte [rdi], 0x0d
    je _is_space_end
    cmp byte [rdi], 0x20
    je _is_space_end
    mov rax, 0
_is_space_end:
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