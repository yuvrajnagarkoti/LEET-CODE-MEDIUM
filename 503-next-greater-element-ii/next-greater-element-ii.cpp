class Solution
{
    
private:
    int search(vector<int>& nums, int index)
    {
        int n = nums.size();
        int curr = nums[index];
        for (int i = 1; i < n; i++)
        {
            int nextIndex = (index + i) % n;
            if (nums[nextIndex] > curr)
            {
                return nums[nextIndex];
            }
        }
        return -1;
    }
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(search(nums, i));
        }
        return ans;
    }
};
