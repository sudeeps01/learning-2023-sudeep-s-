#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_FIELD_SIZE 20

struct LogEntry {
    int entryNo;
    char sensorNo[MAX_FIELD_SIZE];
    float temperature;
    int humidity;
    int light;
    char timestamp[MAX_FIELD_SIZE];
};

void readDataFromCSV(const char *filename, struct LogEntry logEntries[], int *numEntries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file '%s'.\n", filename);
        *numEntries = 0;
        return;
    }

    char line[MAX_FIELD_SIZE * 5]; // Assuming a maximum line length of 5 fields
    *numEntries = 0;

    // Read each line in the file
    while (fgets(line, sizeof(line), file)) {
        // Parse the line and store the data in a structure
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]", &logEntries[*numEntries].entryNo, logEntries[*numEntries].sensorNo,
               &logEntries[*numEntries].temperature, &logEntries[*numEntries].humidity, &logEntries[*numEntries].light,
               logEntries[*numEntries].timestamp);

        (*numEntries)++;

        if (*numEntries >= MAX_ENTRIES) {
            printf("Maximum number of entries reached. Some data may be truncated.\n");
            break;
        }
    }

    fclose(file);
}

void displayLogEntries(const struct LogEntry logEntries[], int numEntries) {
    printf("Log Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Entry No: %d\n", logEntries[i].entryNo);
        printf("Sensor No: %s\n", logEntries[i].sensorNo);
        printf("Temperature: %.1f\n", logEntries[i].temperature);
        printf("Humidity: %d\n", logEntries[i].humidity);
        printf("Light: %d\n", logEntries[i].light);
        printf("Timestamp: %s\n", logEntries[i].timestamp);
        printf("\n");
    }
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    readDataFromCSV("data.csv", logEntries, &numEntries);
    displayLogEntries(logEntries, numEntries);

    return 0;
}
