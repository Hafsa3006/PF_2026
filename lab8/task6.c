#include <stdio.h>

int deposit(float *balance, float amount) {
    if (amount <= 0) {
        return 0;
    }
    *balance += amount;
    return 1;
}

int withdraw(float *balance, float amount) {
    if (amount <= 0 || amount > *balance) {
        return 0;
    }
    *balance -= amount;
    return 1;
}

int main() {
    float balance = 1000.0f;
    int choice;
    float amount;

    do {
        printf("\n1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid choice\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (deposit(&balance, amount)) {
                    printf("Deposit successful.\n");
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (withdraw(&balance, amount)) {
                    printf("Withdrawal successful.\n");
                } else {
                    printf("Invalid amount or insufficient balance.\n");
                }
                break;
            case 3:
                printf("Current balance: %.2f\n", balance);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
