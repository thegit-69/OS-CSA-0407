#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    bool completed;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input details
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        printf("Enter priority for process P%d (lower number = higher priority): ", i + 1);
        scanf("%d", &p[i].priority);
        p[i].remaining_time = p[i].burst_time;
        p[i].completed = false;
    }

    int current_time = 0;
    int completed = 0;
    int prev = -1;
    printf("\nExecution Order:\n");

    while (completed != n) {
        int idx = -1;
        int highest_priority = 9999;

        // Find process with highest priority among arrived and not completed
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && !p[i].completed) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
                // If two processes have same priority, choose earlier arrival
                else if (p[i].priority == highest_priority) {
                    if (p[i].arrival_time < p[idx].arrival_time) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            if (prev != idx) {
                printf("Time %d -> Process P%d\n", current_time, p[idx].pid);
                prev = idx;
            }
            // Execute for 1 time unit
            p[idx].remaining_time--;
            current_time++;

            // If process finished
            if (p[idx].remaining_time == 0) {
                p[idx].completed = true;
                p[idx].turnaround_time = current_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
                completed++;
            }
        } else {
            // If no process is ready, idle time
            current_time++;
        }
    }

    // Print results
    printf("\nProcess Details:\n");
    printf("PID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
            p[i].pid,
            p[i].arrival_time,
            p[i].burst_time,
            p[i].priority,
            p[i].waiting_time,
            p[i].turnaround_time);
    }

    return 0;
}
