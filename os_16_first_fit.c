#include <stdio.h>

int main() {
    int blockSize[10], processSize[10], allocation[10];
    int n, m;

    printf("Enter number of memory blocks: ");
    scanf("%d", &n);
    printf("Enter sizes of memory blocks:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &m);
    printf("Enter sizes of processes:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1; // initially unallocated
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(int i = 0; i < m; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
