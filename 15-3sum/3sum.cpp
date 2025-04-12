class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int i, j, k;
    int low,high;
    for (i = 0; i < nums.size() - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates for i
        low = i + 1;
        high = nums.size() - 1;
        while (low < high)
        {
            int sum = nums[i] + nums[low] + nums[high];
            if (sum == 0)
            {
                ans.push_back({nums[i], nums[low], nums[high]});
                // skip duplicates for low
                while (low < high && nums[low] == nums[low + 1]) low++;
                // skip duplicates for high
                while (low < high && nums[high] == nums[high - 1]) high--;
                low++;
                high--;
            }
            else if (sum < 0)
                low++;
            else
                high--;
        }
    }
    return ans;
    }
};