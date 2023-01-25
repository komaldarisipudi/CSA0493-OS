#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void roundRobin(Process proc[], int quantum) {
    int remaining_time[MAX_PROCESSES];
    int completion_time[MAX_PROCESSES];
    int arrival_time[MAX_PROCESSES];
    int current_time = 0;
    int done = 0;
    int waiting_time = 0;
    int turnaround_time = 0;
    int i, j;

    // Copy burst time to remaining_time[]
    for (i = 0; i < MAX_PROCESSES; i++) {
        remaining_time[i] = proc[i].burst_time;
    }

    // Copy arrival time
    for (i = 0; i < MAX_PROCESSES; i++) {
        arrival_time[i] = proc[i] arrival_time;
    }

    printf("\nProcess\t|Turnaround Time|Waiting Time\n\n");

    for (i = 0; done != MAX_PROCESSES; i++) {
        for (j = 0; j < MAX_PROCESSES; j++) {
            if (arrival_time[j] <= current_time && remaining_time[j] > 0) {
                if (remaining_time[j] > quantum) {
                    current_time += quantum;
                    remaining_time[j] -= quantum;
                } else {
                    current_time += remaining_time[j];
                    completion_time[j] = current_time;
                    remaining_time[j] = 0;
                    done++;
                }
                waiting_time = completion_time[j] - proc[j].burst_time - arrival_time[j];
                turnaround_time = completion_time[j] - arrival_time[j];
                proc[j].waiting_time = waiting_time;
                proc[j].turnaround_time = turnaround_time;
            }
        }
    }

    // Print results
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("P[%d]\t|\t%d\t|\t%d\n", proc[i].pid, proc[i].turnaround_time, proc[i].waiting_time);
    }
}

int main() {
    Process proc[MAX_PROCESSES];
    int i;
    int quantum;

    // Input process information
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("Enter process ID: ");
        scanf("%d", &proc[i].pid);
        printf("Enter burst time: ");
        scanf("%d", &proc[i].burst_time);
        printf("Enter arrival time: ");
        scanf("%d", &proc[i].arrival_time);
    }

    printf("Enter quantum: ");
    scanf("%d", &quantum);

    roundRobin(proc, quantum);
