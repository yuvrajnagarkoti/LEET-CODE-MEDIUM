static inline void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* value of left part > pivot
   value of right part < pivot */
static void partition(int k, int *arr, int start, int end)
{
    if (start >= end || k < 1)
        return;

    int i, l, m, r, pivot;

    pivot = arr[start];
    l = start + 1;
    r = end - 1;
    for (i = l; i <= r; i++) {
        if (arr[i] > pivot)
            swap(&arr[l++], &arr[i]);
        else if (arr[i] < pivot)
            swap(&arr[r--], &arr[i--]);
    }
    swap(&arr[start], &arr[l - 1]);

    if (l <= k && k <= r + 1)
        return;

    if (l > k)
        return partition(k, arr, start, l);
    
    return partition(k, arr, r + 1, end);
}

long long maxSum(int** grid, int gridSize, int* gridColSize, int* limits, int limitsSize, int k)
{
    int *candidates;
    int i, r, c, col_size, cand_size;
    long long res;

    cand_size = 0;
    for (r = 0; r < limitsSize; r++)
        cand_size += limits[r];
    candidates = malloc(cand_size * sizeof(int));

    col_size = *gridColSize;
    i = 0;
    for (r = 0; r < gridSize; r++) {
        partition(limits[r], grid[r], 0, col_size);

        for (c = 0; c < limits[r]; c++)
            candidates[i++] = grid[r][c];
    }

    partition(k, candidates, 0, i);
    res = 0LL;
    for (i = 0; i < k; i++)
        res += candidates[i];

    free(candidates);
    return res;
}