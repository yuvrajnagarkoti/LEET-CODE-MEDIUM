
class Solution
{
public:
    int rec(int i, int prev, vector<int>& nums,vector<vector<int>>& dp)
    {
        int n = nums.size();

        if (i >= n)
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        // Skip current element
        int notTake = rec(i + 1, prev, nums, dp);

        // Take current element if it is increasing
        int take = 0;

        if (prev == -1 || nums[i] > nums[prev])
        {
            take = 1 + rec(i + 1, i, nums, dp);
        }

        return dp[i][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(0, -1, nums, dp); // idx , prev , array , dp
    }
};