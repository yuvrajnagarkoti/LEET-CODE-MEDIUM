class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int m=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(m+nums[i] > nums[i])
                m=m+nums[i];
            else
                m=nums[i];
            ans=max(ans,m);
        }
        return ans;
    }
};