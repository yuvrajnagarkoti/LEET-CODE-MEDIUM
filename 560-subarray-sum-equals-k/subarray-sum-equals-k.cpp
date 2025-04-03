class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0, count = 0;
        // Base case: prefix sum of 0 occurs once
        prefixSumCount[0] = 1;
        for (int num : nums)
        {
            prefixSum += num;
            // Check if (prefixSum - k) exists in the map
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end())
            {
                count += prefixSumCount[prefixSum - k];
            }
            // Store/update prefix sum count in map
            prefixSumCount[prefixSum]++;
        }
        return count;
    }
};