section .text
    global _factorial

_factorial:
                ; rax хранит ответ
    mov rax, 1
                ; rbx - счетчик. изначально равен
                ; входному параметру n
    mov rbx, rdi

_loop:
                ; если счетчик дошел до 0
                ; заканчиваем вычисление
    cmp rbx, 0
    je _ret

                ; умножаем результат на счетчик
    mul rbx
                ; переходим к следующему числу n = (n - 1)
    sub rbx, 1
                ; повторяем цикл
    jmp _loop

_ret:
    ret