#include <stdio.h>

float averageSteps(int *steps, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(steps + i);
    }
    return (float)sum / n;
}

int countGoalDays(int *steps, int n, int goal) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(steps + i) >= goal) {
            count++;
        }
    }
    return count;
}

int main() {
    int steps[7];
    int goal = 8000;

    printf("Enter steps for 7 days:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d: ", i + 1);
        scanf("%d", &steps[i]);
    }

    float avg = averageSteps(steps, 7);
    int goalDays = countGoalDays(steps, 7, goal);

    printf("\nAverage steps: %.2f\n", avg);
    printf("Days reached goal: %d\n", goalDays);

    return 0;
}
