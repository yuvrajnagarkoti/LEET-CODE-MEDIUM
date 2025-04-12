class Solution
{
public:
    void merge(vector<int>& nums, int low, int mid, int high)
    {
        int i, j, k;
        int n1 = mid - low + 1;
        int n2 = high - mid;
        vector<int> leftarr;
        vector<int> rightarr;
        for (i = 0; i < n1; i++)
            leftarr.push_back(nums[low + i]);
        for (j = 0; j < n2; j++)
            rightarr.push_back(nums[mid + 1 + j]);
        i = j = 0;
        k = low;
        while (i < n1 && j < n2)
        {
            if (leftarr[i] < rightarr[j])
                nums[k++] = leftarr[i++];
            else
                nums[k++] = rightarr[j++];
        }
        while (i < n1)
            nums[k++] = leftarr[i++];
        while (j < n2)
            nums[k++] = rightarr[j++];
    }

    void mergesort(vector<int>& nums, int low, int high)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            mergesort(nums, low, mid);
            mergesort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }   
    vector<vector<int>> threeSum(vector<int>& nums)
    {
    vector<vector<int>> ans;
    int low = 0, high = nums.size() - 1;
    mergesort(nums, low, high);
    int i, j, k;
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