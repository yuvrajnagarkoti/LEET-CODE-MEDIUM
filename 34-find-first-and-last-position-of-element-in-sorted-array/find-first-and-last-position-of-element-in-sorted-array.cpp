class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
    
private:
    // Binary search to find the first occurrence of target
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int index = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            if (nums[mid] == target)
                index = mid;
        }
        return index;
    }
    
    // Binary search to find the last occurrence of target
    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int index = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            if (nums[mid] == target)
                index = mid;
        }
        return index;
    }
};
