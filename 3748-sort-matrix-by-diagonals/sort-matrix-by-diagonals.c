// Helper function to sort a diagonal (either ascending or descending)
void sortDiagonal(int **grid, int startRow, int startCol, int n, int ascending)
{
    int size = 0, i = startRow, j = startCol;

    // Count diagonal elements
    while (i < n && j < n)
    {
        size++;
        i++;
        j++;
    }

    // Store diagonal elements in a temporary array
    int *diagonal = (int *)malloc(size * sizeof(int));
    i = startRow;
    j = startCol;
    for (int k = 0; k < size; k++)
    {
        diagonal[k] = grid[i][j];
        i++;
        j++;
    }

    // Sort the diagonal
    for (int x = 0; x < size - 1; x++)
    {
        for (int y = x + 1; y < size; y++)
        {
            if ((ascending && diagonal[x] > diagonal[y]) || (!ascending && diagonal[x] < diagonal[y]))
            {
                int temp = diagonal[x];
                diagonal[x] = diagonal[y];
                diagonal[y] = temp;
            }
        }
    }

    // Put sorted values back into the matrix
    i = startRow;
    j = startCol;
    for (int k = 0; k < size; k++)
    {
        grid[i][j] = diagonal[k];
        i++;
        j++;
    }

    free(diagonal);
}

int **sortMatrix(int **grid, int gridSize, int *gridColSize, int *returnSize, int **returnColumnSizes)
{
    int i;

    // Sort bottom-left diagonals (including middle diagonal) in non-increasing order
    for (i = 0; i < gridSize; i++)
    {
        sortDiagonal(grid, i, 0, gridSize, 0); // 0 -> Descending order
    }

    // Sort top-right diagonals in non-decreasing order
    for (i = 1; i < gridSize; i++)
    {
        sortDiagonal(grid, 0, i, gridSize, 1); // 1 -> Ascending order
    }

    // Set return sizes
    *returnSize = gridSize;
    *returnColumnSizes = (int *)malloc(gridSize * sizeof(int));
    for (i = 0; i < gridSize; i++)
    {
        (*returnColumnSizes)[i] = *gridColSize;
    }
    return grid;
}