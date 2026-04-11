class Solution {
public:
    int minimumDistance(vector<int>& nums)
    {
        int n=nums.size();
        vector<vector<int>> st(n+1);
        for(int i=0;i<nums.size();i++)
        {
            st[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto num : st)
        {
            if(num.size() >= 3)
            {
                int lim = num.size();
                for(int i=0;i+2<lim;i++)
                {
                    int temp = abs(num[i]-num[i+1]) + abs(num[i+1]-num[i+2]) + abs(num[i+2]-num[i]);
                    ans = min(ans,temp);
                }
            }
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};