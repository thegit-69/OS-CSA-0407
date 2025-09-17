#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
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
        p[i].completed = false;
    }

    int current_time = 0;
    int completed = 0;
    printf("\nExecution Order:\n");

    while (completed != n) {
        int idx = -1;
        int min_burst = 9999;

        // Find process with shortest burst time among arrived and not completed
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].arrival_time <= current_time) {
                if (p[i].burst_time < min_burst) {
                    min_burst = p[i].burst_time;
                    idx = i;
                }
                // If two processes have same burst time, choose earlier arrival
                else if (p[i].burst_time == min_burst) {
                    if (p[i].arrival_time < p[idx].arrival_time) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            printf("Time %d -> Process P%d\n", current_time, p[idx].pid);

            // Calculate waiting time and turnaround time
            p[idx].waiting_time = current_time - p[idx].arrival_time;
            current_time += p[idx].burst_time;
            p[idx].turnaround_time = current_time - p[idx].arrival_time;
            p[idx].completed = true;
            completed++;
        } else {
            // If no process is ready, increment time
            current_time++;
        }
    }

    // Print results
    printf("\nProcess Details:\n");
    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,
            p[i].arrival_time,
            p[i].burst_time,
            p[i].waiting_time,
            p[i].turnaround_time);
    }

    return 0;
}
