section .text
    global _bruteforce
    global _lea_sib
    global _abs_if
    global _abs_no_if

_bruteforce:
    mov rax, rdi
    imul rax, 3
    mov rbx, rsi
    imul rbx, 5
    sub rax, rbx
    add rax, rdx
    ret

_lea_sib:
    lea rax, [2 * rdi + rdi]
    lea rbx, [4 * rsi + rsi]
    sub rax, rbx
    add rax, rdx
    ret

_abs_if:
    mov rax, rdi
    cmp rax, 0
    jge _ret
    imul rax, -1

_ret:
    ret

_abs_no_if:
                ; исходное число в rax
    mov rax, rdi
                ; в rbx - противоположное
    mov rbx, rax
    not rbx
    inc rbx
                ; теперь если rax отрицательное
                ; в беззнаковой арифметике
                ; оно строго больше rbx. (и наоборот)
                ; модуль - минимальное значение
    xor rcx, rcx
    cmp rax, rbx
                ; теперь, если в беззнаковой арифметике
                ; rax < rbx, то rax - модуль, а CF=1
    sbb rcx, 0
                ; sbb rcx, 0 => rcx = rcx - 0 - CF
                ; = 0 - 0 - 0 = 0, если rax >= rbx
                ; и 0 - 0 - 1 = -1, если rax < rbx

                ; в rcx лежат все единицы в случае
                ; когда модулем является rax
    and rax, rcx
                ; если модуль - rbx, то в rcx - 0
                ; и, следовательно, в rax тоже 0
    not rcx
    and rbx, rcx
                ; если модуль - rax, то после "not rcx"
                ; в rcx - 0, и следовательно в rbx тоже 0
                ; таким образом, один из rax, rbx не 0
                ; лишь в случае, когда его значение является модулем
                ; => rax+rbx - ответ
    add rax, rbx
    ret

