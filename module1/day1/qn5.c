#include <stdio.h>

int bit_operations(int num, int oper_type) {
    if (oper_type == 1) {  // Set 1st bit
        return num | (1 << 0);
    } else if (oper_type == 2) {  // Clear 31st bit
        return num & (~(1 << 31));
    } else if (oper_type == 3) {  // Toggle 16th bit
        return num ^ (1 << 15);
    } else {
        // Invalid operation type, return the original number
        return num;
    }
}

int main() {
    int num = 123;  // Your 32-bit integer
    int oper_type = 2;  // The operation type (1, 2, or 3)

    int result = bit_operations(num, oper_type);
    printf("%d\n", result);

    return 0;
}
