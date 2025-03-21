#include <stdio.h>
#include <stdlib.h>
int* searchRange(int* nums, int n, int target, int* returnSize)
{
    int *a = (int *)malloc(2 * sizeof(int));
    a[0] = -1;
    a[1] = -1;
    // Find first occurrence
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            a[0] = i;
            break;
        }
    }
    // Find last occurrence
    for (int j = n - 1; j >= 0; j--)
    {
        if (nums[j] == target)
        {
            a[1] = j;
            break;
        }
    }
    *returnSize = 2;
    return a;
}