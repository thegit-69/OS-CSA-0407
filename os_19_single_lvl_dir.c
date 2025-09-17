#include <stdio.h>
#include <string.h>

#define MAX_FILES 100
#define NAME_LEN 50

int main() {
    char files[MAX_FILES][NAME_LEN];
    int fileCount = 0;
    char choice, searchName[NAME_LEN];

    do {
        printf("\nEnter file name to add: ");
        scanf("%s", files[fileCount]);
        fileCount++;

        printf("Add another file? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    printf("\nFiles in directory:\n");
    for(int i = 0; i < fileCount; i++) {
        printf("%s\n", files[i]);
    }

    printf("\nEnter file name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for(int i = 0; i < fileCount; i++) {
        if(strcmp(files[i], searchName) == 0) {
            printf("File '%s' found.\n", searchName);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("File '%s' not found.\n", searchName);
    }

    return 0;
}
