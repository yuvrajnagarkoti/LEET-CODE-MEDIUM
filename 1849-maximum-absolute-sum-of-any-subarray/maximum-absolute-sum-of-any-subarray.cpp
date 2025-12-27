class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int maxs=nums[0];
        int ans1=nums[0];
        int mins=nums[0];
        int ans2=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            maxs = max(maxs+nums[i],nums[i]);
            ans1=max(maxs,ans1);
            mins = min(mins+nums[i],nums[i]);
            ans2=min(mins,ans2);
        }
        return max(ans1,abs(ans2));
    }
};