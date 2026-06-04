class Solution
{
public:
    set<vector<int>> st;
    void rec(vector<int> nums,int i,vector<int> temp)
    {
        if(i==nums.size())
            return;
        st.insert(temp); //not take
        rec(nums,i+1,temp);
        temp.push_back(nums[i]);
        rec(nums,i+1,temp);
        st.insert(temp); // take
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> temp;
        rec(nums,0,temp);
        vector<vector<int>> ans;
        for(auto &v : st)
        {
            ans.push_back(v);
        }
        return ans;
    }
};