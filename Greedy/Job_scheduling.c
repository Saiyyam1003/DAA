#include <stdio.h>
#include <stdlib.h>
// Structure to represent a job
typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

// Function to compare jobs based on their profits (used for sorting)
int compareJobs(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

// Function to find the maximum deadline among all jobs
int findMaxDeadline(Job jobs[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

// Function to schedule jobs and calculate the maximum profit
void scheduleJobs(Job jobs[], int n) {
    // Sort the jobs based on their profits in descending order
    qsort(jobs, n, sizeof(Job), compareJobs);

    // Find the maximum deadline among all jobs
    int maxDeadline = findMaxDeadline(jobs, n);

    // Array to store the final schedule
    int schedule[maxDeadline];

    // Initialize the schedule array with -1 (indicating empty slots)
    for (int i = 0; i < maxDeadline; i++) {
        schedule[i] = -1;
    }

    // Fill the schedule array with jobs
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Display the final schedule and the total profit
    printf("Final Schedule: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (schedule[i] != -1) {
            printf("%d ", schedule[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    // Example jobs
    Job jobs[] = {
        {1, 4, 70},
        {2, 2, 60},
        {3, 4, 50},
        {4, 3, 40},
        {5, 1, 30}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Schedule the jobs and display the result
    scheduleJobs(jobs, n);

    return 0;

}