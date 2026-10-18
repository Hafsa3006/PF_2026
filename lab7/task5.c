#include <stdio.h>

int main()
{
    int a[3][3][3];
    int i, j, k;
    int same;

    printf("Enter elements of the 3D array:\n");

    for (i = 0; i < 3; i++)
    {
        printf("\nEnter elements of Layer %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &a[i][j][k]);
            }
        }
    }

    printf("\nLayer Comparisons:\n");

    for (i = 0; i < 2; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            same = 1;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    if (a[i][r][c] != a[j][r][c])
                    {
                        same = 0;
                    }
                }
            }

            if (same == 1)
            {
                printf("Layer %d and Layer %d are IDENTICAL.\n",
                       i + 1, j + 1);
            }
            else
            {
                printf("Layer %d and Layer %d are DISTINCT.\n",
                       i + 1, j + 1);
            }
        }
    }

    return 0;
}
