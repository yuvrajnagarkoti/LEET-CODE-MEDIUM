// Comparator function for ascending order sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minPairSum(int* nums, int n) {
    // Sort in ascending order (O(n log n))
    qsort(nums, n, sizeof(int), compare);

    // Two-pointer approach to find max pair sum in O(n)
    int maxSum = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int pairSum = nums[i] + nums[j];
        if (pairSum > maxSum) {
            maxSum = pairSum;
        }
    }
    return maxSum;
}