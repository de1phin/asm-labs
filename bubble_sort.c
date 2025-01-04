

/*
 * Сортировка пузырьком
 *
 * Пример:
 * $ nasm -f elf64 -o ./sort.asm.o ./bubble_sort.asm 
 * $ gcc -c -o ./sort.c.o ./bubble_sort.c
 * $ gcc -o ./exe ./sort.c.o ./sort.asm.o 
 * $ ./exe
 * > 7
 * > 3 19 0 5 6 1 9
 * < 0 1 3 5 6 9 19 
 * $
 *
 */


#include "stdio.h"
#include "stdint.h"

extern void _sort(uint64_t, uint64_t*);

int main() {

    uint64_t n;

    scanf("%ld", &n);

    uint64_t arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }

    _sort(n, &arr[0]);

    for (int i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }


    printf("\n");

}
