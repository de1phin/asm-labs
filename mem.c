#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

void allocate(uint64_t bytes) {
    const int n = 4;
    void* mem[n];
    printf("allocate %ld bytes:\n", bytes);
    for (int i = 0; i < n; i++)
        mem[i] = malloc(bytes);
    for (int i = 0; i < n; i++)
        printf("%p ", mem[i]);
    printf("\n");
    printf("diff: ");
    for (int i = 1; i < n; i++)
        printf("%ld ", mem[i] - mem[i - 1]);
    printf("\n");
}

int main() {

    allocate(1);
    allocate(16);
    allocate(32);
    allocate(48);
    allocate(64);
    allocate(1024);
    allocate(1024 * 8);
    allocate(1024 * 128);
    allocate(1024 * 1024);
    uint64_t mb = 1024 * 1024 * 1024;
    allocate(mb);
    allocate(2 * mb);

    return 0;
}
