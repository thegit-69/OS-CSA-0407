#include <stdio.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int completed;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    int totalTime = 0;
    int completedProcesses = 0;

    // Input arrival and burst times
    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &p[i].arrivalTime);
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &p[i].burstTime);
        p[i].waitingTime = 0;
        p[i].turnaroundTime = 0;
        p[i].completed = 0;
    }

    // Sort by arrival time
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].arrivalTime > p[j+1].arrivalTime) {
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    int currentTime = 0;

    while(completedProcesses < n) {
        int idx = -1;
        int minBurst = 1000000;

        // Find process with minimum burst time among arrived and not completed
        for(int i = 0; i < n; i++) {
            if(p[i].arrivalTime <= currentTime && !p[i].completed) {
                if(p[i].burstTime < minBurst) {
                    minBurst = p[i].burstTime;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            p[idx].waitingTime = currentTime - p[idx].arrivalTime;
            if(p[idx].waitingTime < 0)
                p[idx].waitingTime = 0;
            currentTime += p[idx].burstTime;
            p[idx].turnaroundTime = p[idx].waitingTime + p[idx].burstTime;
            p[idx].completed = 1;
            completedProcesses++;
        } else {
            currentTime++; // idle time
        }
    }

    // Print results
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
            p[i].id,
            p[i].arrivalTime,
            p[i].burstTime,
            p[i].waitingTime,
            p[i].turnaroundTime);
    }

    return 0;
}
