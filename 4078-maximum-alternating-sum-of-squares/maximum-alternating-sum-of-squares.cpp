class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());

        long long sum = 0;
        int n = nums.size();
        int mid = n / 2;

        if (n % 2 != 0)
        {
            sum += 1LL * nums[n / 2] * nums[n / 2];
            mid = (n / 2) - 1;
        }
        else
            mid--;
        while (mid >= 0)
        {
            long long t1 = 1LL * nums[mid] * nums[mid];
            long long t2 = 1LL * nums[n - 1] * nums[n - 1];

            sum += t2 - t1;
            mid--;
            n--;
        }

        return sum;
    }
};