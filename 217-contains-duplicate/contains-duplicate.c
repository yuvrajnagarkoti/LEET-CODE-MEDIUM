// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to check for duplicates
int containsDuplicate(int *nums, int n) {
    if (n <= 1) return 0;  // No duplicates possible in size 1 array
    qsort(nums, n, sizeof(int), compare); // Sort the array in O(n log n)
    // Check adjacent elements for duplicates
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return 1; // Duplicate found
        }
    }
    return 0; // No duplicates
}
