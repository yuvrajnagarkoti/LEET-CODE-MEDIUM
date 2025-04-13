class Solution
{
    void backtrack(int ind,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(ind==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            backtrack(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        int n=nums.size();
        int ind=0;
        vector<vector<int>>ans;
        backtrack(ind,nums,ans);
        return ans;
    }
};