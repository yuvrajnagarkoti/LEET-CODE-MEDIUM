class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int n = nums.size();
        int low = 0, high = 0;
        int sum = 0;
        int minl = INT_MAX;
        while (high < n)
        {
            sum += nums[high];
            while (sum >= target)
            {
                minl = min(minl, high - low + 1);
                sum -= nums[low];
                low++;
            }
            high++;
        }

        return minl == INT_MAX ? 0 : minl;
    }
};
