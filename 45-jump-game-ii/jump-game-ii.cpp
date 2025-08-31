class Solution {
public:
    int jump(vector<int>& nums)
    {
        vector<int> dp(nums.size(),INT_MAX);
        dp[0]=0;
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1;
            while( j<nums.size() && j<=i+nums[i] )
            {
                dp[j]= min(dp[j],dp[i]+1);
                j++;
            }
        }
        return dp[nums.size()-1];
    }
};