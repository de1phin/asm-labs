
/*
 * 1) Вычислить значение 3x - 5y + z
 * 1.1) "в лоб"
 * 1.2) с использованием lea + sib
 * 2) Вычислить модуль числа без ветвления
 */

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

extern int64_t _bruteforce(int64_t, int64_t, int64_t);
extern int64_t _lea_sib(int64_t, int64_t, int64_t);

extern int64_t _abs_if(int64_t);
extern int64_t _abs_no_if(int64_t);

int main() {

    int64_t x, y, z;
    scanf("%ld %ld %ld", &x, &y, &z);

    printf("3x - 5y + z =\n");
    printf("C: %ld\n", 3*x -5*y + z);
    printf("ASM (bruteforce): %ld\n", _bruteforce(x, y, z));
    printf("ASM (LEA + SIB): %ld\n", _lea_sib(x, y, z));

    printf("\n(2). |x| = ?\n");
    printf("C: %ld\n", (int64_t)abs(x));
    printf("ASM (with ifs): %ld\n", _abs_if(x));
    printf("ASM (no ifs): %ld\n", _abs_no_if(x));

}
