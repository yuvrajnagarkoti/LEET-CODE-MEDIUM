class Solution
{
    public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long sum = 0, ans = 0;
        int left = 0, right = 0;
        while (right < n)
        {
            freq[nums[right]]++;
            sum += nums[right];
            // If duplicate found, shrink window from left
            while (freq[nums[right]] > 1)
            {
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }
            // If window size is exactly k
            if (right - left + 1 == k)
            {
                ans = max(ans, sum);
                // Shrink window to maintain size k
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return ans;
    }
};
