class Solution
{
public:
    set<vector<int>> st;
    void rec(vector<int> nums,int i,vector<int>temp)
    {
        if(i==nums.size())
        {
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        rec(nums,i+1,temp); //not take
        
        temp.push_back(nums[i]);
        rec(nums,i+1,temp); //take
        temp.pop_back();
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