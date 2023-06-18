#include <stdio.h>

int deleteDigit(int num, int digit) {
    int power = 1;
    int result = 0;
  
    while (num > 0) {
        int currentDigit = num % 10;
        num /= 10;
      
        if (currentDigit != digit) {
            result += currentDigit * power;
            power *= 10;
        }
    }
  
    return result;
}

int findLargestNumber(int num) {
    int largest = 0;
  
    for (int i = 0; i <= 9; i++) {
        int deletedNum = deleteDigit(num, i);
      
        if (deletedNum > largest) {
            largest = deletedNum;
        }
    }
  
    return largest;
}

int main() {
    int num;
  
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
  
    if (num >= 1000 && num <= 9999) {
        int largestNumber = findLargestNumber(num);
        printf("The largest number after deleting a single digit: %d\n", largestNumber);
    } else {
        printf("Invalid input. Please enter a 4-digit number.\n");
    }
  
    return 0;
}
