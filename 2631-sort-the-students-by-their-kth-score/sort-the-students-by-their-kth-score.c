#include <stdio.h>
#include <stdlib.h>

// Global variable for the column index
int sortColumn;

// Custom comparator function for qsort
int compare(const void* a, const void* b) {
    int* row1 = *(int**)a;
    int* row2 = *(int**)b;

    return row2[sortColumn] - row1[sortColumn]; // Descending order
}

int** sortTheStudents(int** score, int m, int* n, int k, int* returnSize, int** returnColumnSizes) {
    // Set the global sorting column
    sortColumn = k;

    // Sort the rows using qsort
    qsort(score, m, sizeof(int*), compare);

    // Allocate memory for returnColumnSizes
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = *n;
    }
    return score;
}
