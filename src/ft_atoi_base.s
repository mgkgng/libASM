global _ft_atoi_base

extern _ft_strlen

_ft_atoi_base:
    enter 0, 0
    call _check_base
    cmp rax, 0
    je _end_error

    mov r12, 0 ; r12 = result
    mov r13, 0 ; r13 = sign (0 = positive, 1 = negative)
    mov r14, 0 ; r14 = base
    mov r15, 0 ; r15 = base_len

_check_base:
    enter 0, 0
    xor rax, rax
    mov r12, rdi
_check_base_loop1:
    cmp byte [rdi], 0
    je _check_base_end
    cmp byte [rdi], 0x2b
    je _check_base_end_false
    cmp byte [rdi], 0x2d
    je _check_base_end_false
    call _is_space
    cmp rax, 0
    je _check_base_end_false
    mov r13, byte [rdi]
    mov r14, rdi
    inc r14
    inc rdi
_check_base_loop2:
    cmp byte [r14], 0
    je _check_base_loop1
    cmp byte [r14], r13
    je _check_base_end_false
    inc r14
    jmp _check_base_loop2
_check_base_end:
    cmp rax, 1
    jle _check_base_end_false
    mov rax, 1
    leave
    ret
_check_base_end_false:
    mov rax, 0
    leave
    ret

; len + duplicate + valid

;_check_base_duplicate:
;_check_base_valid: (+, -, whitespaces not allowed)

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

_end_error:
    mov rax, 0
    leave
    ret

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
    mov rax, 0
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
    mov rax, 1
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