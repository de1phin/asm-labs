
/*
 * Вычисление факториала числа
 *
 * Пример:
 *
 * $ nasm -f elf64 -o ./factorial.asm.o ./factorial.asm
 * $ gcc -c -o ./factorial.c.o ./factorial.c
 * $ gcc -o ./exe ./factorial.c.o ./factorial.asm.o
 * $ ./exe
 * > 0
 * < 0! = 1
 * $ ./exe
 * > 1
 * < 1! = 1
 * $ ./exe
 * > 2
 * < 2! = 2
 * $ ./exe
 * > 3
 * < 3! = 6
 * $ ./exe
 * > 5
 * < 5! = 120
 * $ ./exe
 * > 10
 * < 10! = 3628800
 *
 */

#include "stdio.h"
#include "stdint.h"

extern uint64_t _factorial(uint16_t);

int main() {
    uint16_t n;
    scanf("%hd", &n);

    uint64_t fact = _factorial(n);
    printf("%d! = %ld\n", n, fact);
}
