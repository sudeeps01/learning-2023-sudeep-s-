#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            sum += arr[i];
        }
    }

    printf("Sum of alternate elements: %d\n", sum);

    return 0;
}
