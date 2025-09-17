#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_RECORDS 50
#define RECORD_SIZE 20

struct File {
    char name[20];
    char records[MAX_RECORDS][RECORD_SIZE];
    int recordCount;
};

struct File files[MAX_FILES];
int fileCount = 0;

void createFile() {
    if (fileCount >= MAX_FILES) {
        printf("Error: Maximum file limit reached!\n");
        return;
    }

    printf("Enter file name: ");
    scanf("%s", files[fileCount].name);

    files[fileCount].recordCount = 0;
    printf("File '%s' created successfully.\n", files[fileCount].name);
    fileCount++;
}

void addRecord() {
    char filename[20];
    printf("Enter file name: ");
    scanf("%s", filename);

    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            if (files[i].recordCount >= MAX_RECORDS) {
                printf("Error: Maximum records limit reached for this file!\n");
                return;
            }
            printf("Enter record data: ");
            scanf("%s", files[i].records[files[i].recordCount]);
            files[i].recordCount++;
            printf("Record added successfully.\n");
            return;
        }
    }
    printf("Error: File not found!\n");
}

void displayFile() {
    char filename[20];
    printf("Enter file name to display: ");
    scanf("%s", filename);

    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            printf("\nFile: %s\n", files[i].name);
            printf("Records:\n");
            for (int j = 0; j < files[i].recordCount; j++) {
                printf("%d: %s\n", j + 1, files[i].records[j]);
            }
            return;
        }
    }
    printf("Error: File not found!\n");
}

void accessRecordSequentially() {
    char filename[20];
    int recordNumber;

    printf("Enter file name: ");
    scanf("%s", filename);

    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i].name, filename) == 0) {
            printf("Enter record number to access: ");
            scanf("%d", &recordNumber);

            if (recordNumber > 0 && recordNumber <= files[i].recordCount) {
                printf("\nSequential Access:\n");
                for (int j = 0; j < recordNumber; j++) {
                    printf("%d: %s\n", j + 1, files[i].records[j]);
                }
            } else {
                printf("Error: Invalid record number!\n");
            }
            return;
        }
    }
    printf("Error: File not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Sequential File Allocation ---\n");
        printf("1. Create File\n");
        printf("2. Add Record\n");
        printf("3. Display File\n");
        printf("4. Access Record Sequentially\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createFile(); break;
            case 2: addRecord(); break;
            case 3: displayFile(); break;
            case 4: accessRecordSequentially(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
