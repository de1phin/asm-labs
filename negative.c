
/*
 * Заменить все отрицательные числа в массиве на 0.
 *
 * Пример:
 *
 * $ nasm -f elf64 -o ./negative.asm.o ./negative.asm && gcc -m64 -c -o ./negative.c.o ./negative.c && gcc -o ./exe ./negative.c.o ./negative.asm.o
 * $ ./exe
 * > 5
 * > 1 -1 1 -1 1
 * < 1 0 1 0 1 
 *
 */

#include "stdio.h"
#include "stdint.h"

extern void _remove_negative(int64_t, int64_t*);

int main() {

    int64_t n;
    scanf("%ld", &n);

    int64_t arr[n];

    for (int64_t i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }

    _remove_negative(n, &arr[0]);

    for (int64_t i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");

    return 0;
}