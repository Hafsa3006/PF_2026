#include <stdio.h>

void printGrid(int (*grid)[5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int countNeighbours(int (*grid)[5], int row, int col) {
    int count = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) {
                continue;
            }
            int r = row + dr;
            int c = col + dc;
            if (r >= 0 && r < 5 && c >= 0 && c < 5) {
                count += (grid[r][c] & 1);
            }
        }
    }
    return count;
}

void nextGeneration(int (*grid)[5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int liveNeighbours = countNeighbours(grid, i, j);
            int currentState = grid[i][j] & 1;
            int nextState = 0;

            if (currentState == 1) {
                if (liveNeighbours == 2 || liveNeighbours == 3) {
                    nextState = 1;
                }
            } else {
                if (liveNeighbours == 3) {
                    nextState = 1;
                }
            }

            grid[i][j] |= (nextState << 1);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j] >>= 1;
        }
    }
}

int main() {
    int grid[5][5] = {0};

    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    int generations;

    while (1) {
        printf("Enter the number of generations (0-50): ");
        if (scanf("%d", &generations) != 1) {
            while (getchar() != '\n');
            printf("Invalid size\n");
            continue;
        }

        if (generations < 0 || generations > 50) {
            printf("Invalid size\n");
        } else {
            break;
        }
    }

    printf("\nInitial Generation:\n");
    printGrid(grid);

    for (int g = 1; g <= generations; g++) {
        nextGeneration(grid);
        printf("\nGeneration %d:\n", g);
        printGrid(grid);
    }

    return 0;
}
