#include <stdio.h>

int main() {
    int n, i, time = 0, remain, flag = 0;
    int wait_time = 0, turnaround_time = 0;
    int quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;
    int burst_time[n], remaining_time[n];

    for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    printf("\nProcess execution order:\n");

    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(remaining_time[i] > 0) {
                if(remaining_time[i] > quantum) {
                    printf("P%d -> ", i + 1);
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    printf("P%d -> ", i + 1);
                    time += remaining_time[i];
                    wait_time += time - burst_time[i];
                    turnaround_time += time;
                    remaining_time[i] = 0;
                    remain--;
                }
            }
        }
    }

    printf("END\n");
    printf("Average waiting time = %.2f\n", (float)wait_time / n);
    printf("Average turnaround time = %.2f\n", (float)turnaround_time / n);

    return 0;
}
