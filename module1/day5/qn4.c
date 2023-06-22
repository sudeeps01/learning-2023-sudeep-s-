#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array of structures
    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Read data for each student
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &(students + i)->rollNumber);
        printf("Name: ");
        scanf("%s", (students + i)->name);
        printf("Marks: ");
        scanf("%f", &(students + i)->marks);
    }

    // Display data for each student
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll Number: %d\n", (students + i)->rollNumber);
        printf("Name: %s\n", (students + i)->name);
        printf("Marks: %.2f\n", (students + i)->marks);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
