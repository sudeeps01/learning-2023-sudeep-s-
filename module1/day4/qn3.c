#include <stdio.h>
#include<string.h>
// converting the string to integer
int main() {
    char input[100] ;
     printf("enter  the input \n ");
   fgets(input, sizeof(input), stdin);
    
    // Remove newline character from fgets
    input[strcspn(input, "\n")] = '\0';
    
    int result = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        int digit = input[i] - '0';  // Convert the character to its numeric value
        result = result * 10 + digit;
    }

    printf("The converted integer is: %d\n", result);

    return 0;
}
