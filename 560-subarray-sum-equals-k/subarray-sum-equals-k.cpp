class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> m{{0, 1}};
        int sum = 0, count = 0;
        for (int num : nums)
        {
            sum += num;
            count += m[sum - k];
            m[sum]++;
        }
        return count;
    }
};
