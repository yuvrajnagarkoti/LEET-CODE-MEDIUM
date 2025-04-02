class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        int n=nums.size();
        int negative[n/2];
        int positive[n/2];
        int i,n1=0,p1=0;
        for(i=0;i<n;i++)
        {
            if(nums[i]>=0)
                positive[p1++]=nums[i];
            else
                negative[n1++]=nums[i];
        }
        i=0;
        p1=n1=0;
        while(i<n)
        {
            nums[i++]=positive[p1++];
            nums[i++]=negative[n1++];
        }
        return nums;
    }
};