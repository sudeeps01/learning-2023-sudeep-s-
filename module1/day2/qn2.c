#include <stdio.h>

// Generic swap function using pointers
void swap(void* a, void* b, size_t size) {
    char* p1 = (char*)a;
    char* p2 = (char*)b;

    while (size--) {
        char temp = *p1;
        *p1++ = *p2;
        *p2++ = temp;
    }
}

int main() {
    int a = 10, b = 20;
    swap(&a, &b, sizeof(a));
    printf("After swap: a = %d, b = %d\n", a, b);

    float x = 3.14, y = 2.71;

    swap(&x, &y, sizeof(x));
    printf("After swap: x = %.2f, y = %.2f\n", x, y);

    char c1 = 'A', c2 = 'B';
   
    swap(&c1, &c2, sizeof(c1));
    printf("After swap: c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}
