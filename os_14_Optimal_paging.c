#include <stdio.h>

int predict(int pages[], int frame[], int n, int index, int frames) {
    int res = -1, farthest = index;
    for (int i = 0; i < frames; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n)  // Page not found in future
            return i;
    }
    return (res == -1) ? 0 : res;
}

int main() {
    int n, frames;
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[frames];
    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    int page_faults = 0;
    printf("\nPage Reference\tFrames\t\tPage Fault\n");

    for (int i = 0; i < n; i++) {
        int flag = 0;
        // Check if page already exists in frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If page not found
        if (flag == 0) {
            // If there is empty frame
            int empty_found = 0;
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = pages[i];
                    page_faults++;
                    empty_found = 1;
                    break;
                }
            }

            // If no empty frame, replace using Optimal strategy
            if (!empty_found) {
                int pos = predict(pages, frame, n, i + 1, frames);
                frame[pos] = pages[i];
                page_faults++;
            }
        }

        // Print frames
        printf("%d\t\t", pages[i]);
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        if (flag == 0) printf("\t\tPage Fault");
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    return 0;
}
