
#include <stdio.h>

int square(int x) {
    return x * x;
}

int negate(int x) {
    return -x;
}

int isEven(int x) {
    return (x % 2 == 0);
}

int isPositive(int x) {
    return (x > 0);
}

void applyToArray(int *arr, int n, int (*fn)(int)) {
    for (int i = 0; i < n; i++) {
        *(arr + i) = fn(*(arr + i));
    }
}

int countIf(const int *arr, int n, int (*pred)(int)) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (pred(*(arr + i))) {
            count++;
        }
    }
    return count;
}

void printGeneric(void *data, char type, int n) {
    for (int i = 0; i < n; i++) {
        if (type == 'i') {
            printf("%d ", *((int *)data + i));
        } else if (type == 'f') {
            printf("%.2f ", *((float *)data + i));
        } else if (type == 'c') {
            printf("%c ", *((char *)data + i));
        } else {
            printf("Error: Invalid type\n");
            return;
        }
    }
    printf("\n");
}

int main() {
    int n;
    int arr[50] = {3, -2, 8, -5, 6};

    while (1) {
        printf("Enter n (1-50): ");
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            printf("Invalid size\n");
            continue;
        }

        if (n < 1 || n > 50) {
            printf("Invalid size\n");
        } else {
            break;
        }
    }

    printf("\nOriginal array: ");
    printGeneric(arr, 'i', n);

    applyToArray(arr, n, square);
    printf("After square:   ");
    printGeneric(arr, 'i', n);

    printf("Even count: %d\n", countIf(arr, n, isEven));
    printf("Positive count: %d\n", countIf(arr, n, isPositive));

    return 0;
}
