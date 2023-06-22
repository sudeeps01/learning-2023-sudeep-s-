#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int searchByName(const struct Student *students, int numStudents, const char *targetName) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, targetName) == 0) {
            return i;  // Return the index if name matches
        }
    }

    return -1;  // Return -1 if name not found
}

int main() {
    int numStudents = 3;
    struct Student students[numStudents];

    // Initialize the array of structures
    students[0].rollno = 1001;
    strcpy(students[0].name, "naruto");
    students[0].marks = 90.5;

    students[1].rollno = 1002;
    strcpy(students[1].name, "luffy");
    students[1].marks = 85.0;

    students[2].rollno = 1003;
    strcpy(students[2].name, "goku");
    students[2].marks = 95.0;

    // Perform search operation
    char targetName[20];
    printf("Enter the name to search: ");
    scanf("%s", targetName);

    int index = searchByName(students, numStudents, targetName);

    // Print the search result
    if (index != -1) {
        printf("Student found at index %d:\n", index);
        printf("Roll No: %d\n", students[index].rollno);
        printf("Name: %s\n", students[index].name);
        printf("Marks: %.2f\n", students[index].marks);
    } else {
        printf("Student with name '%s' not found.\n", targetName);
    }

    return 0;
}
