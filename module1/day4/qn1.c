//Reimplement prob –5.9 (No.of days elapsed) if date is given in string format as DD/MM/YYYY
#include <stdio.h>
#include <stdlib.h>
int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int countDaysElapsed(char* dateStr) {
    int day, month, year;
    printf("enter day\n");
    scanf("%d",&day);
    printf("enter month\n");
     scanf("%d",&month);
    printf("enter year\n");
     scanf("%d",&year);

    

    int daysElapsed = 0;
    int i;

    for (i = 1; i < month; i++) {
        daysElapsed += getDaysInMonth(i, year);
    }

    daysElapsed += day;

    return daysElapsed;
}

int main() {
    char dateStr[] = "10/04/2015";
    int daysElapsed = countDaysElapsed(dateStr);
    printf("Number of days elapsed: %d\n", daysElapsed);

    return 0;
}
