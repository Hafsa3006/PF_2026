
#include <stdio.h>

int main()
{
    int a[3][3][3];
    int i, j, k;
    int sum, total = 0;
    int largest, smallest;
    int f_largest, f_smallest;

    printf("Enter 27 elements of the 3D array:\n");

    for (i = 0; i < 3; i++)
    {
        printf("\nEnter elements for Layer %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &a[i][j][k]);
            }
        }
    }

    f_largest = a[0][0][0];
    f_smallest = a[0][0][0];

    for (i = 0; i < 3; i++)
    {
        sum = 0;
        largest = a[i][0][0];
        smallest = a[i][0][0];

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                sum += a[i][j][k];
                total += a[i][j][k];

                if (a[i][j][k] > largest)
                    largest = a[i][j][k];

                if (a[i][j][k] < smallest)
                    smallest = a[i][j][k];

                if (a[i][j][k] > f_largest)
                    f_largest = a[i][j][k];

                if (a[i][j][k] < f_smallest)
                    f_smallest = a[i][j][k];
            }
        }

        printf("\nLayer %d Results:\n", i + 1);
        printf("Sum = %d\n", sum);
        printf("Average = %.2f\n", sum / 9.0);
        printf("Largest element = %d\n", largest);
        printf("Smallest element = %d\n", smallest);
    }

    printf("\nOverall Results:\n");
    printf("Total sum = %d\n", total);
    printf("Overall average = %.2f\n", total / 27.0);
    printf("Overall largest element = %d\n", f_largest);
    printf("Overall smallest element = %d\n", f_smallest);

    return 0;
}

