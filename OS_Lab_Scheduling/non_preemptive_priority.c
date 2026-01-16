#include <stdio.h>

int main() {

    int n;
    int burst_time[20], priority[20], process_id[20];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        process_id[i] = i + 1;
        printf("P%d (burst time): ", i + 1);
        scanf("%d", &burst_time[i]);

        printf("P%d (priority): ", i + 1);
        // Read the input for priority.
        scanf("%d", &priority[i]);
    }


    // Sort the processes based on their priority in ascending order (lower is higher priority).
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the priority of the current process is higher than the one it's being compared to.
            if (priority[j] < priority[i]) {
                int temp;
                
                // Swap the priorities.
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // Swap the burst times to maintain consistency with the priorities.
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                // Swap the process IDs as well, so we know which process is which after sorting.
                temp = process_id[i];
                process_id[i] = process_id[j];
                process_id[j] = temp;
            }
        }
    }

    int time = 0;
    // Loop through the sorted processes to calculate their completion time.
    for (int i = 0; i < n; i++) {
        time += burst_time[i];
        printf("Process %d finished at time %d\n", process_id[i], time);
    }
    
    return 0;
}
