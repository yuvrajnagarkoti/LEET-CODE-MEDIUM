#include <stdio.h>
#include <stdlib.h>

// Comparator function for ascending order sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

#define max(a, b) ((a) > (b) ? (a) : (b))  // Macro to find max

int minPairSum(int* nums, int n) {
    // Step 1: Sort the array in ascending order
    qsort(nums, n, sizeof(int), compare);

    // Step 2: Find the maximum pair sum
    int maxSum = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        maxSum = max(maxSum, nums[i] + nums[j]);
    }

    return maxSum;
}