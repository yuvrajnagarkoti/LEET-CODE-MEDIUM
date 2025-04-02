class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        int i,k=nums.size();
        int a[k];
        int p=0,n=1;
        for(i=0;i<k;i++)
        {
            if(nums[i]>=0)
            {
                a[p]=nums[i];
                p=p+2;
            }
            else
            {
                a[n]=nums[i];
                n=n+2;
            }
        }
        for(i=0;i<k;i++)
            nums[i]=a[i];
        return nums;
    }
};