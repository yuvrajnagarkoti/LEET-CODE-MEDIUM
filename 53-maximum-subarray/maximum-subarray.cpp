class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int ans=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(sum+nums[i] > nums[i])
            {
                sum=sum+nums[i];
            }
            else
            {
                sum=nums[i];
            }
            
            ans=max(sum,ans);
        }
        return ans;
    }
};