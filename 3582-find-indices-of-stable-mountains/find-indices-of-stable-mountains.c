/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* stableMountains(int* height, int n, int threshold, int* returnSize)
{
    int * a= (int *)calloc(100,sizeof(int ));
    int i,k=0;
    for(i=1;i<n;i++)
    {
        if(height[i-1]>threshold && height[i]!= 0)
        {
            a[k++]=i;
        }
    }
    *returnSize=k;
    return a;
}