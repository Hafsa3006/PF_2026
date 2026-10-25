#include <stdio.h>

void printArray(const int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void reverseArray(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    int arr[20];

    while (1) {
        printf("Enter the number of songs (1-20): ");
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

    printf("Enter %d song IDs:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal playlist: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Reversed playlist: ");
    printArray(arr, n);

    return 0;
}
