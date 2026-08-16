class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        int ans=0,cursum=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            cursum = cursum + nums[i];
            int temp = cursum-goal;
            if(mpp.find(temp) != mpp.end())
            {
                ans = ans + mpp[temp];
            }
            mpp[cursum]++;
        }
        return ans;
    }
};