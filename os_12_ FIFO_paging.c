#include <stdio.h>

int main() {
    int i, j, n, f, page[50], frame[10], count = 0, k = 0, flag;
    
    // Input number of pages
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    // Input page reference string
    printf("Enter page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    // Input number of frames
    printf("Enter number of frames: ");
    scanf("%d", &f);
    
    // Initialize frames as empty
    for (i = 0; i < f; i++) {
        frame[i] = -1;
    }
    
    printf("\nPage Reference String\tFrames\t\tPage Fault\n");
    
    // FIFO Page Replacement
    for (i = 0; i < n; i++) {
        flag = 0;
        
        // Check if page already in frame
        for (j = 0; j < f; j++) {
            if (frame[j] == page[i]) {
                flag = 1;
                break;
            }
        }
        
        // If page not found, replace using FIFO
        if (flag == 0) {
            frame[k] = page[i];
            k = (k + 1) % f;  // Move to next frame in circular way
            count++;
        }
        
        // Print frames
        printf("%d\t\t\t", page[i]);
        for (j = 0; j < f; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        if (flag == 0)
            printf("\t\tPage Fault");
        printf("\n");
    }
    
    printf("\nTotal Page Faults: %d\n", count);
    return 0;
}
