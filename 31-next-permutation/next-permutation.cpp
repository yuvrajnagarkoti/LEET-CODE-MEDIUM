class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size(), i = n - 2;
        // Find first index from the end where nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = n - 1;
            // Find the next greater element from the end
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        // Reverse the part after index i to get the next permutation
        reverse(nums.begin() + i + 1, nums.end());
    }
};