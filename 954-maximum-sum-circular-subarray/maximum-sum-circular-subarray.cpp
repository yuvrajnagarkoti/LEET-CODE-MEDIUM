class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int mins = nums[0];
        int ans1 = nums[0];
        int maxs = nums[0];
        int ans2 = nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            mins=min(mins+nums[i],nums[i]);
            ans1=min(ans1,mins);

            maxs=max(maxs+nums[i],nums[i]);
            ans2=max(ans2,maxs);
        }
        if (ans2 < 0) return ans2;
        return max(sum-ans1 , ans2);
    }
};