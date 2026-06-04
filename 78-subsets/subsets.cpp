class Solution
{
public:
    vector<vector<int>> ans;

    void rec(vector<int>& nums, int i, vector<int>& temp)
    {
        if(i == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        // Not take
        rec(nums, i + 1, temp);

        // Take
        temp.push_back(nums[i]);
        rec(nums, i + 1, temp);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> temp;
        rec(nums, 0, temp);
        return ans;
    }
};