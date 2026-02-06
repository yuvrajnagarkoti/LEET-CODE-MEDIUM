class Solution {
public:
    int minRemoval(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        int ans = n;

        for(int j = 0; j < n; j++)
        {
            while(nums[j] > (long long)nums[i] * k)
            {
                i++;   // only move left pointer
            }
            ans = min(ans, n - (j - i + 1));
        }
        return ans;
    }
};
