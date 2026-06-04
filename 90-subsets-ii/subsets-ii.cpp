class Solution
{
public:
    set<vector<int>> st;
    void rec(vector<int> nums,int i,vector<int> temp)
    {
        if(i==nums.size())
            return;
        sort(temp.begin(),temp.end());
        st.insert(temp); //not take
        rec(nums,i+1,temp);
        temp.push_back(nums[i]);
        rec(nums,i+1,temp);
        sort(temp.begin(),temp.end());
        st.insert(temp); // take
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
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