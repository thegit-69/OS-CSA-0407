#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int main() {
    int n, head, diskSize;
    char direction[10];

    printf("Enter disk size: ");
    scanf("%d", &diskSize);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter direction (inward/outward): ");
    scanf("%s", direction);

    printf("Enter number of requests: ");
    scanf("%d", &n);
    int queue[n+1]; // adding one if needed for disk end
    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    sort(queue, n);

    int index = 0;
    for(int i = 0; i < n; i++) {
        if(queue[i] >= head) {
            index = i;
            break;
        }
    }

    int seek = 0;
    printf("\nHead movements:\n");

    if(strcmp(direction, "inward") == 0) {
        // Move toward smaller cylinders first
        for(int i = index-1; i >= 0; i--) {
            printf("%d -> %d with movement %d\n", head, queue[i], abs(head - queue[i]));
            seek += abs(head - queue[i]);
            head = queue[i];
        }
        // Move toward larger cylinders
        for(int i = index; i < n; i++) {
            printf("%d -> %d with movement %d\n", head, queue[i], abs(head - queue[i]));
            seek += abs(head - queue[i]);
            head = queue[i];
        }
    } else {
        // Move toward larger cylinders first
        for(int i = index; i < n; i++) {
            printf("%d -> %d with movement %d\n", head, queue[i], abs(head - queue[i]));
            seek += abs(head - queue[i]);
            head = queue[i];
        }
        // Move toward smaller cylinders
        for(int i = index-1; i >= 0; i--) {
            printf("%d -> %d with movement %d\n", head, queue[i], abs(head - queue[i]));
            seek += abs(head - queue[i]);
            head = queue[i];
        }
    }

    printf("\nTotal head movement = %d\n", seek);
    return 0;
}
 