#include <stdio.h>

int main() {

    int n, time_quantum;
    int burst_time[20], remaining_time[20];
    

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter burst time for each process:\n");

    // Loop 'n' times to get the burst time for each process.
    for (int i = 0; i < n; i++) {

        printf("P%d: ", i + 1);
        scanf("%d", &burst_time[i]);

        // Initialize the remaining_time for each process to be the same as its burst time.
        remaining_time[i] = burst_time[i];
    }
    

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);
    

    int time = 0;
    int completed = 0;
    // The main loop continues as long as not all processes are completed.
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            // Check if the process still has time remaining to execute.
            if (remaining_time[i] > 0) {
                if (remaining_time[i] <= time_quantum) {
                    time += remaining_time[i];
                    // Set the remaining time for this process to 0, as it's now finished.
                    remaining_time[i] = 0;
                    completed++;
                    printf("Process %d finished at time %d\n", i + 1, time);
                } else {
                    // If the remaining time is greater than the time quantum,
                    // the process will run for the full duration of the time quantum.
                    time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
            }
        }
    }
    
    return 0;
}
