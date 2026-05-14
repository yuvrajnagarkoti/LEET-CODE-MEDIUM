class Solution {
public:
    bool isGood(vector<int>& nums)
    {
        map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        if(mpp.size() != n-1)
            return false;
        for(auto it : mpp)
        {
            if( (it.first < n-1 && it.second > 1) || (it.first == n-1 && it.second != 2))
            {
                return false;
            }
            if( it.first > n-1)
                return false;
        }
        return true;
    }
};