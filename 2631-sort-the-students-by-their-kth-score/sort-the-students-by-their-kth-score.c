#include <stdlib.h>

void swaprows(int **score, int r1, int r2, int n) {
    for (int i = 0; i < n; i++) {
        int temp = score[r1][i];
        score[r1][i] = score[r2][i];
        score[r2][i] = temp;
    }
}

int** sortTheStudents(int** score, int m, int* n, int k, int* returnSize, int** returnColumnSizes) {
    // Sort the matrix in-place based on the k-th column in descending order
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (score[i][k] < score[j][k]) {
                swaprows(score, i, j, *n);
            }
        }
    }
    // Set return values
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int)); // Allocate memory
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = *n; // Each row has 'n' columns
    }
    return score;
}
