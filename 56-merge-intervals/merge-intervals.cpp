class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums)
    {
        sort(nums.begin(),nums.end());
        int low=nums[0][0],high=nums[0][0];
        vector<vector<int>> ans;

        for(int i=0;i<nums.size();i++)
        {
            int p1=nums[i][0];
            int p2=nums[i][1];

            if(high < p1)
            {
                ans.push_back({low,high});
                low=p1;
                high=p2;
            }
            else if(p1 <= high)
            {
                high = max(high,p2);
            }
        }
        ans.push_back({low,high});

        return ans;
    }
};