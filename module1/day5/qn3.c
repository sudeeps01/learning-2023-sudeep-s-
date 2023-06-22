#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time calculateTimeDifference(struct Time t1, struct Time t2) {
    struct Time diff;

    // Convert the time periods to seconds
    int totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Calculate the absolute difference in seconds
    int difference = totalSeconds1 - totalSeconds2;
    if (difference < 0) {
        difference = -difference;
    }

    // Convert the difference back to hours, minutes, and seconds
    diff.hours = difference / 3600;
    difference %= 3600;
    diff.minutes = difference / 60;
    difference %= 60;
    diff.seconds = difference;

    return diff;
}

int main() {
    struct Time time1, time2, difference;

    printf("Enter the first time period:\n");
    printf("Hours: ");
    scanf("%d", &(time1.hours));
    printf("Minutes: ");
    scanf("%d", &(time1.minutes));
    printf("Seconds: ");
    scanf("%d", &(time1.seconds));

    printf("Enter the second time period:\n");
    printf("Hours: ");
    scanf("%d", &(time2.hours));
    printf("Minutes: ");
    scanf("%d", &(time2.minutes));
    printf("Seconds: ");
    scanf("%d", &(time2.seconds));

    difference = calculateTimeDifference(time1, time2);

    printf("\nDifference between the time periods: %02d:%02d:%02d\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
