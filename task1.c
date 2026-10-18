#include <stdio.h>

int main() { 
    int mat[3][3] = {{7, 9, 11}, {3, 11, 5}, {8, 1, 4}};
    int transpose[3][3];
    int co_factors[3][3];
    int ADJ[3][3];
    float INV[3][3];
    
    int i = 0, j = 0, k = 0, l = 0;
    float det = 0;

    // 1. TRANSPOSE
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            transpose[i][j] = mat[j][i];
        }
    }
    
    printf("TRANSPOSE\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");  
    }

    // 2. CO-FACTORS
    for(i = 0; i < 3; i++) { 
        for(j = 0; j < 3; j++) {
            int M[2][2];
            int sr = 0;
            for(k = 0; k < 3; k++) {
                if(k == i) continue;
                int sc = 0;
                for(l = 0; l < 3; l++) {
                    if(l == j) continue;
                    M[sr][sc] = mat[k][l]; 
                    sc++;
                }
                sr++;
            }
            int det2 = M[0][0] * M[1][1] - M[0][1] * M[1][0];
            if((i + j) % 2 != 0) {
                det2 = det2 * (-1);
            }
            co_factors[i][j] = det2;
        }
    }
    
    printf("CO-FACTORS\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", co_factors[i][j]);
        }
        printf("\n");
    }

    // 3. DETERMINANT (Calculated using the first row expansion with cofactors)
    det = mat[0][0] * co_factors[0][0] + mat[0][1] * co_factors[0][1] + mat[0][2] * co_factors[0][2];
    printf("DETERMINANT\n%.2f\n", det);

    // 4. ADJOINT (Transpose of the cofactor matrix)
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            ADJ[j][i] = co_factors[i][j];
        }
    }
    
    printf("ADJOINT\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", ADJ[i][j]);
        }
        printf("\n");  
    }

    // 5. INVERSE
    if(det == 0) {
        printf("INVERSE IS NOT POSSIBLE :/\n");
    } else {
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                INV[i][j] = ADJ[i][j] / det;
            }
        }
        
        printf("INVERSE\n");
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                printf("%.2f ", INV[i][j]);
            }
            printf("\n");
        }
    }
       
    return 0;
}
