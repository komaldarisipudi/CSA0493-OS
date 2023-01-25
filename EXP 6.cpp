#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;
    int priority;
    int burst_time;
    int waiting_time;
    int completion_time;
};

// Function to find the process with the highest priority
int highestPriority(struct Process processes[], int n, int time) {
    int highest_priority = INT_MAX;
    int highest_priority_index = -1;
    for (int i = 0; i < n; i++) {
        if (processes[i].burst_time > 0 && processes[i].priority < highest_priority) {
            highest_priority = processes[i].priority;
            highest_priority_index = i;
        }
    }
    return highest_priority_index;
}

int main() {
    // Initialize an array of processes with sample data
    struct Process processes[MAX_PROCESSES] = {
        {1, 3, 5, 0, 0},
        {2, 1, 4, 0, 0},
        {3, 4, 2, 0, 0},
        {4, 2, 6, 0, 0},
        {5, 5, 1, 0, 0}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    // Sort the processes in ascending order of priority
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].priority > processes[j].priority) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Keep track of the current time
    int time = 0;
    for (int i = 0; i < n; i++) {
        int current_process = highestPriority(processes, n, time);
        if (current_process != -1) {
            time += processes[current_process].burst_time;
            processes[current_process].burst_time = 0;
            processes[current_process].waiting_time = time - processes[current_process].burst_time;
            processes[current_process].completion_time = time;
        }
    }

    // Print out the results
    printf("Process ID\tPriority\tBurst Time\tWaiting Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].priority, 
            processes[i].burst_time, processes[i].waiting_time, processes[i].completion_time);
    }

    return 0;
}

