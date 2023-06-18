#include <stdio.h>
#include <stdint.h>

// Function to print the exponent part of a double variable
void printExponent(double num) {
    uint64_t* ptr = (uint64_t*)&num;
    uint64_t exponentMask = 0x7FF0000000000000;
    uint64_t exponentBits = (*ptr & exponentMask) >> 52;

    printf("Exponent in hexadecimal: 0x%lx\n", exponentBits);
    printf("Exponent in binary: 0b");
    for (int i = 11; i >= 0; i--) {
        printf("%d", (exponentBits >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printf("Value: %lf\n", x);
    printExponent(x);
    return 0;
}
