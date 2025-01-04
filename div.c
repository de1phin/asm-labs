#include "stdio.h"
#include "stdint.h"

/*
 * Команды div/idiv (mul/imul аналогично)
 * Вычисление результата деления (с остатком) целых чисел
 *
 * Далее по коду указаны результаты работы команд
 * в соответствии с реализацией.
 *
 */

extern int64_t _div(int64_t, int64_t);
extern int64_t _mod(int64_t, int64_t);
extern int64_t _idiv(int64_t, int64_t);
extern int64_t _imod(int64_t, int64_t);
// Для простоты делаю shr константно для деления на 4
extern int64_t _div_by_4(int64_t);
extern int64_t _mod_2pow(int64_t, int64_t);

int main() {

    int64_t a = 13; int64_t b = 4;
    printf("%ld / %ld:\n", a, b);
    printf("div: %ld\n", _div(a, b));
    // => div: 3
    printf("idiv: %ld\n", _idiv(a, b));
    // => idiv: 3
    printf("2pow: %ld\n", _div_by_4(a));
    // => 2pow: 3


    printf("%ld %% %ld:\n", a, b);
    printf("mod: %ld\n", _mod(a, b));
    // => mod: 1
    printf("imod: %ld\n", _imod(a, b));
    // => imod: 1
    printf("2pow: %ld\n", _mod_2pow(a, b));
    // => 2pow: 1

    printf("\nNegative\n\n");

    a = -13;
    printf("%ld / %ld:\n", a, b);
    printf("div: %ld\n", _div(a, b));
    // => div: 4611686018427387900
    // так как -13 в беззнаковом варианте - большое число)
    printf("idiv: %ld\n", _idiv(a, b));
    // => idiv: -3
    // idiv справляется с отрицательными числами
    printf("2pow: %ld\n", _div_by_4(a));
    // => 2pow: 4611686018427387900
    // аналогично div, знак не учитывается и всё идёт
    // не так, как надо

    printf("%ld %% %ld:\n", a, b);
    printf("mod: %ld\n", _mod(a, b));
    // => mod: 3
    // - неправильно
    printf("imod: %ld\n", _imod(a, b));
    // => imod: -1
    // - правильно
    printf("2pow: %ld\n", _mod_2pow(a, b));
    // => 2pow: 3
    // аналогично div
    
    // Таким образом, разные реализации деления
    // приводят к разным результатам; так, например,
    // нельзя использовать операции сдвига и побитового "И"
    // при делении на степень двойки, если делимое отрицательное

    return 0;
}
