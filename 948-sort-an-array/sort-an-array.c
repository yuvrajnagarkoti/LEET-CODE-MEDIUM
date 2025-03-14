int* sortArray(int* nums, int n, int* returnSize) {
    int i, j;
    // Find min and max values
    int min = nums[0], max = nums[0];
    for (i = 1; i < n; i++) {
        if (nums[i] > max)
            max = nums[i];
        if (nums[i] < min)
            min = nums[i];
    }

    // Adjust size to handle negative numbers
    int range = max - min + 1;
    // Allocate and initialize count array
    int* count = (int*)calloc(range, sizeof(int));
    
    // Fill count array
    for (i = 0; i < n; i++) {
        count[nums[i] - min]++;
    }

    // Reconstruct sorted array
    j = 0;
    for (i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            nums[j++] = i + min; // Shift back to original value
            count[i]--;
        }
    }
    // Free allocated memory
    free(count);
    *returnSize = n;
    return nums;
}