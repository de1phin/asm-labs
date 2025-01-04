section .text
    global _div
    global _idiv
    global _mod
    global _imod
    global _div_by_4
    global _mod_2pow

_div:
    mov rax, rdi
    xor rdx, rdx
    div rsi
    ret

_idiv:
    mov rax, rdi
    xor rdx, rdx
    cqo ; idiv = (rdx:rax / rsi)
        ; в беззнаковом варианте нужно оставить rdx нулём
        ; в знаковом - в соответствии с знаком rax
    idiv rsi
    ret

_div_by_4:
    mov rax, rdi
    shr rax, 2
    ret

_mod:
    mov rax, rdi
    xor rdx, rdx
    div rsi
    mov rax, rdx
    ret

_imod:
    mov rax, rdi
    xor rdx, rdx
    cqo
    idiv rsi
    mov rax, rdx
    ret

_mod_2pow:
    mov rax, rdi
    mov rbx, rsi
    sub rbx, 1
    and rax, rbx
    ret

