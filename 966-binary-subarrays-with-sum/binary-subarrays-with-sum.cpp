class Solution {
private:
    int numSubarraysWithAtMostSum(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int i = 0, count = 0, cursum = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            cursum += nums[j];
            while (cursum > goal) {
                cursum -= nums[i];
                i++;
            }
            count += (j - i + 1); // Length of window = number of valid subarrays ending at j
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithAtMostSum(nums, goal) - numSubarraysWithAtMostSum(nums, goal - 1);
    }
};