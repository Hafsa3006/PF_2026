
#include <stdio.h>

int sumShelf(const int *shelf, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += *(shelf + i);
    }
    return sum;
}

int findLargestShelf(const int *counts, int totalShelves) {
    int maxIndex = 0;
    int maxCount = *counts;
    for (int i = 1; i < totalShelves; i++) {
        if (*(counts + i) > maxCount) {
            maxCount = *(counts + i);
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int shelfA[] = {101, 102, 103};
    int shelfB[] = {201, 202};
    int shelfC[] = {301, 302, 303, 304};

    int *shelves[] = {shelfA, shelfB, shelfC};
    int counts[] = {3, 2, 4};
    int numShelves = 3;

    for (int i = 0; i < numShelves; i++) {
        int sum = sumShelf(shelves[i], counts[i]);
        printf("Shelf %c total ID sum: %d\n", 'A' + i, sum);
    }

    int largest = findLargestShelf(counts, numShelves);
    printf("\nShelf %c holds the most books.\n", 'A' + largest);

    return 0;
}
