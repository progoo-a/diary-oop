#include <stdio.h>

int sum128(const int values[128]) {
    int total = 0;
    for (int i = 0; i < 128; ++i) {
        total += values[i];
    }
    return total;
}

int main(void) {
    int data[128];
    for (int i = 0; i < 128; ++i) {
        data[i] = i + 1;
    }

    int total = sum128(data);
    printf("Somme des 128 valeurs: %d\n", total);
    return 0;
}
