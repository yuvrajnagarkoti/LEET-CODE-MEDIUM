// Function to sort intervals based on start time
void sort(int** intervals, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (intervals[i][0] > intervals[j][0] || 
               (intervals[i][0] == intervals[j][0] && intervals[i][1] > intervals[j][1])) {
                // Swap intervals
                int temp0 = intervals[i][0];
                int temp1 = intervals[i][1];
                intervals[i][0] = intervals[j][0];
                intervals[i][1] = intervals[j][1];
                intervals[j][0] = temp0;
                intervals[j][1] = temp1;
            }
        }
    }
}

// Function to merge overlapping intervals
int** merge(int** intervals, int n, int* m, int* returnSize, int** returnColumnSizes) {
    if (n == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Sort intervals by start time
    sort(intervals, n);

    // Allocate memory for the merged intervals
    int** merged = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    int index = 0;  // Tracks number of merged intervals

    // First interval is always part of the result
    merged[index] = (int*)malloc(2 * sizeof(int));
    merged[index][0] = intervals[0][0];
    merged[index][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= merged[index][1]) {
            // Overlapping intervals: Merge
            if (intervals[i][1] > merged[index][1]) {
                merged[index][1] = intervals[i][1];
            }
        } else {
            // No overlap: Move to next merged interval
            index++;
            merged[index] = (int*)malloc(2 * sizeof(int));
            merged[index][0] = intervals[i][0];
            merged[index][1] = intervals[i][1];
        }
    }

    *returnSize = index + 1; // Number of merged intervals

    // Store column sizes (each interval has 2 elements)
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return merged;
}
