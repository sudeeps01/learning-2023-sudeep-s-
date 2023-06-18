#include <stdio.h>
#include <stdarg.h>

void findMinMaxDigits(int n, ...) {
    va_list args;
    va_start(args, n);

    int smallestDigit = 9;
    int largestDigit = 0;

    for (int i = 0; i < n; i++) {
        int number = va_arg(args, int);
        int temp = number;

        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;

            if (digit < smallestDigit) {
                smallestDigit = digit;
            }

            if (digit > largestDigit) {
                largestDigit = digit;
            }
        }
    }

    va_end(args);

    printf("Smallest Digit: %d\n", smallestDigit);
    printf("Largest Digit: %d\n", largestDigit);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Not Valid\n");
        return 0;
    }

    int numbers[n];

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    findMinMaxDigits(n, numbers[0], numbers[1], numbers[2]); // Assuming n is 3, adjust the arguments accordingly for more numbers

    return 0;
}
