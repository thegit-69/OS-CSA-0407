#include <stdio.h>
#include <string.h>

#define MAX_DIRS 10
#define MAX_FILES 10
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    char files[MAX_FILES][NAME_LEN];
    int fileCount;
} Directory;

int main() {
    Directory dirs[MAX_DIRS];
    int dirCount = 0;
    char choice, fileName[NAME_LEN], searchName[NAME_LEN];

    do {
        printf("\nEnter directory name: ");
        scanf("%s", dirs[dirCount].name);
        dirs[dirCount].fileCount = 0;

        char fileChoice;
        do {
            printf("Enter file name to add in '%s': ", dirs[dirCount].name);
            scanf("%s", dirs[dirCount].files[dirs[dirCount].fileCount]);
            dirs[dirCount].fileCount++;

            printf("Add another file in '%s'? (y/n): ", dirs[dirCount].name);
            scanf(" %c", &fileChoice);
        } while(fileChoice == 'y' || fileChoice == 'Y');

        dirCount++;
        printf("Add another directory? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    printf("\nDirectory structure:\n");
    for(int i = 0; i < dirCount; i++) {
        printf("Directory: %s\n", dirs[i].name);
        for(int j = 0; j < dirs[i].fileCount; j++) {
            printf("  File: %s\n", dirs[i].files[j]);
        }
    }

    printf("\nEnter file name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for(int i = 0; i < dirCount; i++) {
        for(int j = 0; j < dirs[i].fileCount; j++) {
            if(strcmp(dirs[i].files[j], searchName) == 0) {
                printf("File '%s' found in directory '%s'.\n", searchName, dirs[i].name);
                found = 1;
                break;
            }
        }
        if(found) break;
    }
    if(!found) {
        printf("File '%s' not found.\n", searchName);
    }

    return 0;
}
