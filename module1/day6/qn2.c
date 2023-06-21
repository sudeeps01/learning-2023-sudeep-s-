#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to change the text case to Upper Case
void toUpperCase(char* str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

// Function to change the text case to Lower Case
void toLowerCase(char* str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

// Function to change the text case to Sentence Case
void toSentenceCase(char* str) {
    int firstChar = 1;
    while (*str) {
        if (firstChar) {
            *str = toupper((unsigned char)*str);
            firstChar = 0;
        } else {
            *str = tolower((unsigned char)*str);
        }
        if (*str == '.' || *str == '?' || *str == '!') {
            firstChar = 1;
        }
        str++;
    }
}

// Function to perform the file copy operation with text case handling
void copyFile(const char* srcFilename, const char* destFilename, char option) {
    FILE* srcFile = fopen(srcFilename, "r");
    if (srcFile == NULL) {
        printf("Failed to open the source file.\n");
        return;
    }

    FILE* destFile = fopen(destFilename, "w");
    if (destFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(srcFile);
        return;
    }

    int ch;
    while ((ch = fgetc(srcFile)) != EOF) {
        if (option == 'u') {
            ch = toupper(ch);
        } else if (option == 'l') {
            ch = tolower(ch);
        } else if (option == 's') {
            char c = (char)ch;
            toSentenceCase(&c);
            ch = c;
        }
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");

    fclose(srcFile);
    fclose(destFile);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <option> <src_file> <dest_file>\n", argv[0]);
        return 1;
    }

    char option = 'n'; // 'n' for normal copy
    if (argc >= 5) {
        option = argv[1][1];
    }

    copyFile(argv[2], argv[3], option);

    return 0;
}
