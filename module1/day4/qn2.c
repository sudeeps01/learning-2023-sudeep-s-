#include <stdio.h>
#include <ctype.h>
#include<string.h>
// uppercase to lower case

void convertToLowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char str[100] ;
    printf("enter the words ");
   fgets(str, sizeof(str), stdin);
    
    // Remove newline character from fgets
    str[strcspn(str, "\n")] = '\0';
    
    convertToLowercase(str);
    
    printf("After conversion: %s\n", str);
    
    return 0;
}
