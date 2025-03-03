int compare(const void *a,const void *b)
{
    return (*(int*)a - *(int*)b);
}

int minPairSum(int* nums, int n)
{
    int i,j;
    qsort(nums,n,sizeof(int),compare);
    int max= nums[0]+nums[n-1];
    for(i=1,j=n-2 ; i<j ; i++,j--)
    {
        if(max < nums[i]+nums[j])
        {
            max =nums[i]+nums[j];
        }
    }
    return max;
}