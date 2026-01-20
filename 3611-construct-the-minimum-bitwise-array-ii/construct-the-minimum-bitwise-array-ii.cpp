class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums)
    {
        vector<int> ans;
        for(auto n : nums)
        {
            if(n%2 == 0)
                ans.push_back(-1);
            else
            {
                int t= n+1;
                int lowbit = t & -t;
                ans.push_back(n- (lowbit >> 1));
            }
        }
        return ans;
    }
};