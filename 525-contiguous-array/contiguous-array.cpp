class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        int n=nums.size();
        int cursum=0,ans=0;
        map<int,int> mpp;
        mpp[0] = -1;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
                cursum--;
            else
                cursum++;
            if(mpp.find(cursum) != mpp.end())
            {
                ans = max(ans,i-mpp[cursum]);
            }
            else
            {
                mpp[cursum] = i;
            }
        }
        return ans;
    }
};