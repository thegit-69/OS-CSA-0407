#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    // Input burst time and priority
    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &p[i].burstTime);
        printf("Enter priority for process %d (lower value = higher priority): ", i+1);
        scanf("%d", &p[i].priority);
        p[i].waitingTime = 0;
        p[i].turnaroundTime = 0;
    }

    // Sort processes by priority (lower value = higher priority)
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].priority > p[j+1].priority) {
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    int currentTime = 0;
    for(int i = 0; i < n; i++) {
        p[i].waitingTime = currentTime;
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
        currentTime += p[i].burstTime;

        totalWaitingTime += p[i].waitingTime;
        totalTurnaroundTime += p[i].turnaroundTime;
    }

    // Print results
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
            p[i].id,
            p[i].burstTime,
            p[i].priority,
            p[i].waitingTime,
            p[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time = %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time = %.2f\n", totalTurnaroundTime / n);

    return 0;
}
