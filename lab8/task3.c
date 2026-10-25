#include <stdio.h>

int isValidMark(int m) {
    if (m >= 0 && m <= 100) {
        return 1;
    }
    return 0;
}

void findMinMax(const int *arr, int size, int *min, int *max) {
    *min = *arr;
    *max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < *min) {
            *min = *(arr + i);
        }
        if (*(arr + i) > *max) {
            *max = *(arr + i);
        }
    }
}

int main() {
    int marks[5];
    int minMark, maxMark;

    for (int i = 0; i < 5; i++) {
        while (1) {
            printf("Enter mark for student %d (0-100): ", i + 1);
            int input;
            if (scanf("%d", &input) != 1) {
                while (getchar() != '\n');
                printf("Invalid mark, enter again\n");
                continue;
            }
            if (isValidMark(input)) {
                marks[i] = input;
                break;
            } else {
                printf("Invalid mark, enter again\n");
            }
        }
    }

    findMinMax(marks, 5, &minMark, &maxMark);

    printf("\nLowest mark: %d\n", minMark);
    printf("Highest mark: %d\n", maxMark);

    return 0;
}
