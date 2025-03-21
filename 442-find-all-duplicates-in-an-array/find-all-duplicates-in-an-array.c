int* findDuplicates(int* nums, int n, int* returnSize)
{
    int *count = (int *)calloc(n + 1, sizeof(int));
    int *arr = (int *)malloc(n * sizeof(int));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        count[nums[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (count[i] > 1)
        {
            arr[k++] = i;
        }
    }
    free(count);
    *returnSize = k;
    return arr;
}