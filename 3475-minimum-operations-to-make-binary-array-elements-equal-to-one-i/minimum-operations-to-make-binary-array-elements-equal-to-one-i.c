int minOperations(int* nums, int n)
{
    int i;
    int count=0;
    for (int i = 0; i < n-2; i++)
    {
        if (nums[i] == 0)
        {
            // Flip this triplet (i, i+1, i+2)
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0) return -1;
    }
    return count;
}