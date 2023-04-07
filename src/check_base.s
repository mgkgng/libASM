global _check_base

_check_base:
    enter 8, 0
    xor rax, rax
    xor rcx, rcx
    push rdi
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
    mov rax, 1
    pop rdi
    leave
    ret
_check_base_end_false:
    pop rdi
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