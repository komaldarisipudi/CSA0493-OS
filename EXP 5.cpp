#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;
    int priority;
    int burst_time;
};

int main() {
    // Initialize an array of processes with sample data
    struct Process processes[MAX_PROCESSES] = {
        {1, 3, 5},
        {2, 1, 4},
        {3, 4, 2},
        {4, 2, 6},
        {5, 5, 1}
    };

    // Find the process with the highest priority
    int highest_priority = 0;
    int highest_priority_index = 0;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].priority > highest_priority) {
            highest_priority = processes[i].priority;
            highest_priority_index = i;
        }
    }

    // Execute the process with the highest priority
    printf("Executing process %d with priority %d and burst time %d\n", 
        processes[highest_priority_index].pid, 
        processes[highest_priority_index].priority, 
        processes[highest_priority_index].burst_time);

    return 0;
}
