
#include <stdio.h>

int main()
{
    int a[5][5];
    int r, c, i, j;
    int zero = 1;
    int identity = 1;
    int diagonal = 1;
    int scalar = 1;
    int upper = 1;
    int lower = 1;
    int symmetric = 1;
    int skew = 1;

    input:
    printf("Enter number of rows (1-5): ");
    scanf("%d", &r);

    printf("Enter number of columns (1-5): ");
    scanf("%d", &c);

    if (r < 1 || r > 5 || c < 1 || c > 5)
    {
        printf("Invalid matrix size. ");
        goto input;
    }

    printf("Enter matrix elements:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    /* Check basic matrix types */

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
                zero = 0;

            if (i == j)
            {
                if (a[i][j] != 1)
                    identity = 0;

                if (i == 0 && j == 0)
                    ;
                else if (a[i][j] != a[0][0])
                    scalar = 0;
            }
            else
            {
                if (a[i][j] != 0)
                {
                    identity = 0;
                    diagonal = 0;
                }
            }

            if (i > j && a[i][j] != 0)
                upper = 0;

            if (i < j && a[i][j] != 0)
                lower = 0;
        }
    }

    if (r == c)
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (a[i][j] != a[j][i])
                    symmetric = 0;

                if (a[i][j] != -a[j][i])
                    skew = 0;
            }
        }
    }
    else
    {
        identity = 0;
        diagonal = 0;
        scalar = 0;
        upper = 0;
        lower = 0;
        symmetric = 0;
        skew = 0;
    }

    /* Display all applicable types */

    if (r == c)
        printf("Square Matrix\n");
    else
        printf("Rectangular Matrix\n");

    if (zero == 1)
        printf("Zero Matrix\nNull Matrix\n");

    if (identity == 1)
        printf("Identity Matrix\n");

    if (diagonal == 1)
        printf("Diagonal Matrix\n");

    if (scalar == 1 && diagonal == 1)
        printf("Scalar Matrix\n");

    if (upper == 1)
        printf("Upper Triangular Matrix\n");

    if (lower == 1)
        printf("Lower Triangular Matrix\n");

    if (symmetric == 1)
        printf("Symmetric Matrix\n");

    if (skew == 1)
        printf("Skew-Symmetric Matrix\n");

    if (r == 1)
        printf("Row Matrix\n");

    if (c == 1)
        printf("Column Matrix\n");

    return 0;
}
