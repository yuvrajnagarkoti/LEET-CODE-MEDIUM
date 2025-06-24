class Solution {
public:
    int robRange(vector<int>& nums, int start, int end)
    {
        int left = 0, right = 0;
        for (int i = start; i <= end; i++)
        {
            int temp = max(left + nums[i], right);
            left = right;
            right = temp;
        }
        return right;
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};
