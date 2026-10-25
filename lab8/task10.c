#include <stdio.h>

int add(int a, int b, int *result) {
    *result = a + b;
    return 1;
}

int subtract(int a, int b, int *result) {
    *result = a - b;
    return 1;
}

int multiply(int a, int b, int *result) {
    *result = a * b;
    return 1;
}

int divide(int a, int b, int *result) {
    if (b == 0) {
        return 0;
    }
    *result = a / b;
    return 1;
}

int main() {
    int (*ops[])(int, int, int *) = {add, subtract, multiply, divide};
    int choice;
    int a, b, result;

    do {
        printf("\n1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid choice\n");
            continue;
        }

        if (choice == 5) {
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice\n");
            continue;
        }

        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);

        if (ops[choice - 1](a, b, &result)) {
            printf("Result: %d\n", result);
        } else {
            printf("Error: Division by zero\n");
        }

    } while (1);

    return 0;
}
