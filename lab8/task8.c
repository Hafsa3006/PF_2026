#include <stdio.h>

void computeTotals(int (*marks)[3], int rows, int totals[]) {
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += *(*(marks + i) + j);
        }
        *(totals + i) = sum;
    }
}

int findTopper(const int *totals, int rows) {
    int maxIndex = 0;
    int maxValue = *totals;
    for (int i = 1; i < rows; i++) {
        if (*(totals + i) > maxValue) {
            maxValue = *(totals + i);
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int marks[3][3];
    int totals[3];

    printf("Enter marks for 3 students in 3 subjects:\n");
    for (int i = 0; i < 3; i++) {
        printf("Student %d: ", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    computeTotals(marks, 3, totals);

    printf("\nStudent Totals:\n");
    for (int i = 0; i < 3; i++) {
        printf("Student %d: %d\n", i + 1, totals[i]);
    }

    int topper = findTopper(totals, 3);
    printf("\nStudent %d is the topper!\n", topper + 1);

    return 0;
}
