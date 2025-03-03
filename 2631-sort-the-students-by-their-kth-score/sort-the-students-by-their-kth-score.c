#include <stdlib.h>

void swaprows(int **score, int r1, int r2, int n)
{
    int i, temp;
    for (i = 0; i < n; i++)
    {
        temp = score[r1][i];
        score[r1][i] = score[r2][i];
        score[r2][i] = temp;
    }
}

int** sortTheStudents(int** score, int m, int* n, int k, int* returnSize, int** returnColumnSizes)
{
    // Allocate memory for the new sorted matrix
    int** sortedMatrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        sortedMatrix[i] = (int*)malloc((*n) * sizeof(int));
        for (int j = 0; j < *n; j++)
        {
            sortedMatrix[i][j] = score[i][j]; // Copy original matrix
        }
    }
    // Sort using selection sort (descending order)
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (sortedMatrix[i][k] < sortedMatrix[j][k])
            {
                swaprows(sortedMatrix, i, j, *n);
            }
        }
    }
    // Allocate memory for returnColumnSizes and set values
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        (*returnColumnSizes)[i] = *n;
    }

    return sortedMatrix;
}
