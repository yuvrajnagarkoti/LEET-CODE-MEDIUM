class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> result;
        // Count frequencies of each element
        for (int num : nums) {
            freq[num]++;
        }
        // Check which elements appear more than n/3 times
        for (auto& ans : freq) {
            if (ans.second > n / 3) {
                result.push_back(ans.first);
            }
        }
        return result;
    }
};