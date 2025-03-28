int compare(const void* a, const void* b)
{
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    // Sort the intervals based on the start value
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    // Allocate memory for the result
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    int index = 0; // Tracks position in the result array
    result[index] = intervals[0];
    (*returnColumnSizes)[index] = 2;
    // Iterate through sorted intervals and merge
    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i][0] <= result[index][1])
        {   // Overlapping condition
            // Merge intervals by updating the end time
            if (intervals[i][1] > result[index][1]) {
                result[index][1] = intervals[i][1];
            }
        }
        else
        {   // Non-overlapping interval
            index++;
            result[index] = intervals[i];
            (*returnColumnSizes)[index] = 2;
               (*returnColumnSizes)[index] = 2;
        }
    }
    *returnSize = index + 1;
    return result;
}