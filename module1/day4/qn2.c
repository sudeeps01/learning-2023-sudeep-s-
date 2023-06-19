#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isValidEmail(const char* email) {
    int i, atIndex, dotIndex;
    int usernameLen = 0;
    int domainLen = 0;
    int extensionLen = 0;
    int valid = 1;

    // Find the position of the @ symbol
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atIndex = i;
            break;
        }
    }

    // Check if @ symbol exists
    if (email[i] == '\0') {
        valid = 0;
    } else {
        // Check username
        for (i = 0; i < atIndex; i++) {
            if (!isalnum(email[i]) && email[i] != '.') {
                valid = 0;
                break;
            } else if (isalpha(email[i])) {
                usernameLen++;
            }
        }

        // Check domain name and extension
        for (i = atIndex + 1; email[i] != '\0'; i++) {
            if (!isalpha(email[i]) || isupper(email[i])) {
                valid = 0;
                break;
            }

            if (email[i] == '.') {
                dotIndex = i;
                break;
            } else {
                domainLen++;
            }
        }

        // Check extension
        if (valid) {
            for (i = dotIndex + 1; email[i] != '\0'; i++) {
                if (!isalpha(email[i]) || isupper(email[i])) {
                    valid = 0;
                    break;
                } else {
                    extensionLen++;
                }
            }
        }
    }

    // Validate length restrictions
    if (usernameLen > 64 || domainLen > 253 || extensionLen > 3) {
        valid = 0;
    }

    return valid;
}

int main() {
    char email[100];
    printf("Enter an email address: ");
    scanf("%s", email);

    int valid = isValidEmail(email);
    printf("The email address \"%s\" is %s\n", email, valid ? "Valid" : "Invalid");

    return 0;
}
