#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int no_of_frames, no_of_pages, pages[50], frame[10], time[10];
    int i, j, pos, faults = 0, counter = 0, flag1, flag2;

    // Input
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");
    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    // Initialize frames
    for (i = 0; i < no_of_frames; ++i) {
        frame[i] = -1;
    }

    printf("\nPage Reference\tFrames\t\tPage Fault\n");

    // LRU Page Replacement Algorithm
    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;

        // Check if page already in frame
        for (j = 0; j < no_of_frames; ++j) {
            if (frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page not found and frame is not full
        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frame[j] == -1) {
                    counter++;
                    faults++;
                    frame[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If frame is full, replace LRU page
        if (flag2 == 0) {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frame[pos] = pages[i];
            time[pos] = counter;
        }

        // Print frames
        printf("%d\t\t", pages[i]);
        for (j = 0; j < no_of_frames; ++j) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        if (flag1 == 0) printf("\t\tPage Fault");
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
