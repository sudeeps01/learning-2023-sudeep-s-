#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseInputString(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for Student %d:\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &(students[i].rollno));

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Marks: ");
        scanf("%f", &(students[i].marks));

        printf("\n");
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student *students = malloc(numStudents * sizeof(struct Student));

    parseInputString(students, numStudents);

    // Print the parsed input
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students);

    return 0;
}
