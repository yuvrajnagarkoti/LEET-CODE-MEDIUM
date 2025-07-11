class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int i, n = nums.size();
        int sum = 0;
        for (i = 0; i < n; i++)
        {
            sum = sum + nums[i];
            if (nums[i] >= target)
                return 1;
        }
        if (sum < target)
            return 0;
 
        int low = 0;
        sum = nums[0];
        int m = INT_MAX;
        for (i = 1; i < n; i++)
        {
            sum = sum + nums[i];
            while (sum >= target)
            {
                m = min(m, i - low + 1);
                sum = sum - nums[low++];
            }
        }
        return m;
    }
};