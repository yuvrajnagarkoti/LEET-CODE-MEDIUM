// Function to compare two elements for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to count unique pairs with difference k
int findPairs(int *nums, int n, int k)
{
    qsort(nums, n, sizeof(int), compare); // Sort the array
    int count = 0;
    int i = 0, j = 1;
    while (j < n) {
        if (i == j || nums[j] - nums[i] < k) {
            j++;
        } 
        else if (nums[j] - nums[i] > k) {
            i++;
        } 
        else {
            count++;
            i++; j++;
            while (j < n && nums[j] == nums[j - 1]) j++;
        }
    }
    return count;
}