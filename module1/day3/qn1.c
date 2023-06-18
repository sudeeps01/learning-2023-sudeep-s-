#include <stdio.h>

void print_numbers(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d", i);
    }
      
    for (i = n ; i >= 1; i--) {
        printf("%d", i);
    }
    printf("\n");
}
void pattern_generator(int n) {
    int i;
    for (i = n; i >= 1; i--) {
        print_numbers(i);       
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    pattern_generator(n);
    return 0;
}
