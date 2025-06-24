class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int i,j,n=nums.size();
        if(n==1)    return nums[0];
        if(n==2)    return max(nums[0],nums[1]);
        if(n==3)    return max( max(nums[0],nums[1]) , max(nums[2],nums[0]+nums[2]) );
        vector<int> sum(n,0);
        sum[0] = nums[0];
        for(i=1;i<n;i++)
        {
            int max1=nums[i];
            for(j=i-2;j>=0;j--)
            {
                int temp = nums[i] + sum[j];
                if(max1 < temp)
                {
                    max1 = temp;
                }
            }
            sum[i] = max1;
        }
        int max1=INT_MIN;
        for(i=0;i<n;i++)
        {
            if(sum[i] > max1)
                max1 = sum[i];
        }
        return max1;
    }
};