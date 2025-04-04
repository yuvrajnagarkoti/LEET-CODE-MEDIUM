class Solution
{
public:
    int search(vector<int>& nums, int target)
    {   
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // If mid element is the target
            if (nums[mid] == target) 
                return mid;
            // Check if the left half is sorted
            if (nums[low] <= nums[mid])
            {
                if (target >= nums[low] && target < nums[mid]) 
                    high = mid - 1;  // Search in the left half
                else 
                    low = mid + 1;   // Search in the right half
            } 
            // Right half is sorted
            else
            {
                if (target > nums[mid] && target <= nums[high]) 
                    low = mid + 1;   // Search in the right half
                else 
                    high = mid - 1;  // Search in the left half
            }
        }
        return -1;  // Target not found
    }
};