// Merge function for Merge Sort
void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int *temp = (int *)malloc((high - low + 1) * sizeof(int));

    while (i <= mid && j <= high) {
        if (arr[i] > arr[j]) // Sorting in decreasing order
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];

    free(temp);
}

// Merge Sort function (Descending order)
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Function to calculate max sum
long long maxSum(int** grid, int gridSize, int* gridColSize, int* limits, int limitsSize, int k) {
    int i, j, count = 0;
    long long sum = 0;

    // Allocate an array to store selected elements
    int *selected = (int *)malloc(gridSize * (*gridColSize) * sizeof(int));

    // Extract top 'limits[i]' elements from each row
    for (i = 0; i < gridSize; i++) {
        mergeSort(grid[i], 0, gridColSize[i] - 1); // Sort row in descending order
        for (j = 0; j < limits[i] && j < gridColSize[i]; j++) {
            selected[count++] = grid[i][j];
        }
    }

    // Sort selected elements in descending order
    mergeSort(selected, 0, count - 1);

    // Sum up to k largest elements
    for (i = 0; i < k && i < count; i++) {
        sum += selected[i];
    }

    free(selected);
    return sum;
}
