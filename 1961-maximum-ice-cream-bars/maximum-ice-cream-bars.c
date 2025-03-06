// Function to perform Count Sort
void countSort(int arr[], int n) {
    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Allocate memory for count array
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Store the count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify the count array to store cumulative count
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array to store sorted elements
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    // Free dynamically allocated memory
    free(count);
}

// Function to determine max ice creams that can be bought
int maxIceCream(int *costs, int size, int coins) {
    countSort(costs, size);

    int i = 0;
    while (i < size && coins >= costs[i]) {  // Ensure coins >= costs[i]
        coins -= costs[i];
        i++;
    }
    return i;
}
