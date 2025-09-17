#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, seek = 0;
    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter number of requests: ");
    scanf("%d", &n);
    int queue[n];
    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("\nHead movements:\n");
    for(int i = 0; i < n; i++) {
        printf("%d -> %d with movement %d\n", head, queue[i], abs(head - queue[i]));
        seek += abs(head - queue[i]);
        head = queue[i];
    }

    printf("\nTotal head movement = %d\n", seek);
    return 0;
}
