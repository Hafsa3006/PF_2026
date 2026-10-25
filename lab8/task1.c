#include <stdio.h>

void printArray(const int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void bubbleSort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int n;
    int arr[20];

    while (1) {
        printf("Enter the number of scores (1-20): ");
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            printf("Invalid size\n");
            continue;
        }
        
        if (n < 1 || n > 20) {
            printf("Invalid size\n");
        } else {
            break;
        }
    }

    printf("Enter %d exam scores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nScores before sorting: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Scores after sorting:  ");
    printArray(arr, n);

    return 0;
}
