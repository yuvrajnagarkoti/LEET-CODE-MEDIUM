class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int num : nums)
            if (num < pivot)
                ans.push_back(num);

        for (int num : nums)
            if (num == pivot)
                ans.push_back(num);

        for (int num : nums)
            if (num > pivot)
                ans.push_back(num);

        return ans;
    }
};