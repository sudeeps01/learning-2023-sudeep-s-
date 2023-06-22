#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        students[i].rollno = 0;                     // Initialize roll number to 0
        strncpy(students[i].name, "Unknown", sizeof(students[i].name));  // Initialize name to "Unknown"
        students[i].name[sizeof(students[i].name) - 1] = '\0';          // Ensure name is null-terminated
        students[i].marks = 0.0;                    // Initialize marks to 0.0
    }
}

int main() {
    int numStudents = 3;
    struct Student students[numStudents];

    initializeStudents(students, numStudents);

    // Print the initialized values
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    return 0;
}
