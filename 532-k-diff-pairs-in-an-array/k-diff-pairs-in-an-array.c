int compare(const void* a, const void* b) 
{
    return (*(int*)a - *(int*)b); // Sorting function
}

int findPairs(int* nums, int numsSize, int k) 
{
    if (k < 0) return 0; // No valid pairs if k is negative
    qsort(nums, numsSize, sizeof(int), compare); // Sort the array
    int left = 0, right = 1, count = 0;
    while (left < numsSize) 
    {
        while (right < numsSize && (nums[right] - nums[left] < k || left == right)) 
            right++;
        // Check if we found a valid pair
        if (right < numsSize && nums[right] - nums[left] == k) 
        {
            count++;
        }
        // Move left to the next unique number to ensure uniqueness
        int current = nums[left];
        while (left < numsSize && nums[left] == current) 
            left++;
    }
    return count;
}