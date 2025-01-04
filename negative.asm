section .text
    global _remove_negative

_remove_negative:
    mov rax, 0  ; rax - счетчик цикла
_loop:

                ; помещаем в rbx значение массива
                ; по индексу rax.
                ; rsi - указатель на массив
    mov rbx, QWORD[rsi + rax * 8]
                ; если >= 0
                ; пропускаем установление в 0
    cmp rbx, 0
    jge _skip_make_0

                ; устанавливаем значение 0
    mov QWORD[rsi + rax * 8], 0

_skip_make_0:
                ; увеличиваем счетчик
    add rax, 1
                ; сравниваем с длиной массива
    cmp rax, rdi
                ; если меньше - продолжаем цикл
    jb _loop

    ret